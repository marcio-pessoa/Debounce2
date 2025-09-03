/* Debounce2.cpp - Avoid Bounce Effect Library
 *
 */

#include "Debounce2.h"
#include "Arduino.h"

Debounce2::Debounce2() {}

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

  _state = digitalRead(_pin);
  _period_counter = millis();
  _interval_counter = millis();
}

bool Debounce2::read() {
  if (millis() - _interval_counter < _interval) {
    return false;
  }

  bool currentState = digitalRead(_pin);
  if (currentState != _state) {
    _period_counter = millis();
    _state = currentState;
  } else {
    if (millis() - _period_counter >= _period) {
      bool isPressedState = (_pullup) ? !_state : _state;
      if (isPressedState) {
        _interval_counter = millis();
        return true;
      }
    }
  }

  return false;
}
