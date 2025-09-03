#include <Debounce2.h>

// Define the pins for the button and LED
const byte BUTTON_PIN = 2;
const byte LED_PIN = 13; // The built-in LED on most Arduino boards

// Create a Debounce2 object to handle the button
Debounce2 button;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set up the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Attach the button to pin 2.
  // We use the internal pull-up resistor, so the button should be
  // connected between the pin and GND.
  // Debounce period is 50ms.
  // Interval between presses is 500ms.
  button.attach(BUTTON_PIN, 50, 500, true);

  Serial.println("Debounce2 example sketch started.");
}

void loop() {
  // The read() method checks the button state. It should be called
  // repeatedly in the loop.
  bool pressed = button.read();

  // If the button is pressed, turn on the LED and print a message.
  if (pressed) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button pressed!");
  } else {
    // Otherwise, turn the LED off.
    digitalWrite(LED_PIN, LOW);
  }

  // A small delay to make the serial output readable.
  delay(10);
}
