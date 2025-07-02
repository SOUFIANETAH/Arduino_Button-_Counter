# Arduino_Button-_Counter


This is a basic Arduino project that demonstrates how to use two buttons to increment and reset a counter with proper debounce handling.

---

## Description

- **Count Button** (connected to pin 2): Press this button to increment the counter.
- **Reset Button** (connected to pin 3): Press this button to reset the counter to zero.
- The counter value is printed to the Serial Monitor.

The code uses software debounce to avoid counting multiple times from a single press due to mechanical bouncing of the buttons.

---

## Hardware Setup

- Connect a push button between **pin 2** and GND (Count Button).
- Connect another push button between **pin 3** and GND (Reset Button).
- Use the Arduino's internal pull-up resistors (no external resistors required).

---

## How to Use

1. Upload the sketch to your Arduino.
2. Open the Serial Monitor at **115200 baud**.
3. Press the count button to increase the counter.
4. Press the reset button to reset the counter to zero.
5. The current counter value will be displayed after each button press.

---

## Code Highlights

- Uses `INPUT_PULLUP` mode for buttons.
- Implements software debounce with a 50 ms delay.
- Displays feedback through the Serial Monitor.

---



*Created by Soufiane*

