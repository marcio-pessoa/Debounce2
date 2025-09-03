/* Debounce2.h - Avoid Bounce Effect Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 */

#ifndef Debounce2_h
#define Debounce2_h

#include "Arduino.h"

class Debounce2 {
 public:
  Debounce2();
  /**
   * @brief Attaches the debouncer to a pin.
   *
   * @param pin The pin to which the component is attached.
   * @param period The debounce period in milliseconds.
   * @param interval The interval in milliseconds to wait for a new press.
   * @param pullup Set to true to use the internal pull-up resistor.
   */
  void attach(byte pin, unsigned int period = 50, unsigned int interval = 500,
              bool pullup = false);
  /**
   * @brief Reads the debounced state of the pin.
   * This method should be called repeatedly in the loop.
   *
   * @return true if the pin is considered pressed, false otherwise.
   */
  bool read();

 private:
  byte _pin;
  unsigned int _period;
  unsigned int _interval;
  unsigned long _period_counter;
  unsigned long _interval_counter;
  bool _pullup;
  bool _state;
};

#endif
