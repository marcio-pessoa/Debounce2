# Arduino Avoid Bounce Effect Library: Debounce2

`Debounce2` is a simple Arduino library for debouncing digital inputs, such as buttons and switches. It helps to ensure that you read a clean, stable signal from a noisy input, avoiding multiple triggers from a single press.

## Features

- Easy to use: Attach to a pin with a single line of code.
- Configurable debounce period and repeat interval.
- Supports both pull-up and pull-down resistor configurations.
- Lightweight and efficient.

## Installation

1.  Download the latest release from the [GitHub repository](https://github.com/marcio-pessoa/Debounce2).
2.  In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...` and select the downloaded file.
3.  You can now include the library in your sketches: `#include <Debounce2.h>`

## Usage

Here is a basic example of how to use the `Debounce2` library to read a button press and turn on the built-in LED on an Arduino board.

```cpp
#include <Arduino.h>
#include <Debounce2.h>

const byte BUTTON_PIN = 2;
const byte LED_PIN = 13;

// Create a new Debounce2 object
Debounce2 button;

void setup() {
  // Attach the button to pin 2, with a 50ms debounce period.
  // Using internal pull-up resistor.
  button.attach(BUTTON_PIN, 50, 500, true);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read the button state
  if (button.read()) {
    // If the button is pressed, turn on the LED
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Otherwise, turn it off
    digitalWrite(LED_PIN, LOW);
  }
}
```

## API Reference

### `Debounce2()`

The constructor. Creates a new `Debounce2` object.

### `void attach(byte pin, unsigned int period = 50, unsigned int interval = 500, bool pullup = false)`

Attaches the debouncer to a specific pin.

- `pin`: The Arduino pin to which the button or switch is connected.
- `period`: The time in milliseconds for which the input must be stable to be considered a valid state change. Defaults to `50ms`.
- `interval`: The time in milliseconds to wait before another press can be registered. Defaults to `500ms`.
- `pullup`: Set to `true` if you are using the internal pull-up resistor. Defaults to `false`.

### `bool read()`

Reads the debounced state of the input. This function should be called repeatedly in your `loop()`.

- **Returns:** `true` if a valid press is detected, `false` otherwise.
