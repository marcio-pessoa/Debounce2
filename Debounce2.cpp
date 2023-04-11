/* Debounce2.cpp - Avoid Bounce Effect Library
 *
 */

#include "Debounce2.h"
#include "Arduino.h"

Debounce2::Debounce2() {}

/// @brief
/// @param pin switch Arduino pin
/// @param period time period to validade if switch is pressed (millis)
/// @param interval time interval to disable switch after pressed (millis)
/// @param pullup does switch use pull up resistor? (bool)
void Debounce2::attach(byte pin, unsigned int period, unsigned int interval,
                       bool pullup) {
  _pin = pin;
  _period = period;
  _interval = interval;
  _pullup = pullup;

  if (_pullup) {
    pinMode(_pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }

  _period_counter = millis();
  _interval_counter = millis();
}

/// @brief Check if switch is pressed
/// @return true when pressed
bool Debounce2::check() {
  if (millis() - _interval_counter < _interval) {
    return false;
  }

  if (millis() - _period_counter < _period) {
    Serial.println(".");
    if (_state != digitalRead(_pin)) {
      _state = digitalRead(_pin);
      _period_counter = millis();
    } else {
      if ((not _pullup and _state) or (_pullup and not _state)) {
        _period_counter = millis();
        _interval_counter = millis();
        return true;
      }
    }
  }

  if (millis() - _period_counter >= _period) {
    _period_counter = millis();
  }

  return false;
}
