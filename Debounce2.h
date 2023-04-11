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
  void attach(byte pin, unsigned int period = 50, unsigned int interval = 500,
              bool pullup = false);
  bool check();

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
