const int countButtonPin = 2;   // Button to count
const int resetButtonPin = 3;   // Button to reset

int counter = 0;

// Debounce variables
bool countButtonState = HIGH;         // Current state of button
bool lastCountButtonState = HIGH;     // Previous state
unsigned long lastCountDebounceTime = 0;

bool resetButtonState = HIGH;
bool lastResetButtonState = HIGH;
unsigned long lastResetDebounceTime = 0;

const unsigned long debounceDelay = 50;  // Debounce time

void setup() {
  pinMode(countButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  Serial.begin(115200);

  Serial.println("=== Arduino Counter ===");
  Serial.println("Count Button: Pin 2");
  Serial.println("Reset Button: Pin 3");
  Serial.println("Press count button to increment.");
  Serial.println("=======================");
  Serial.print("Counter: ");
  Serial.println(counter);
}

void loop() {
  checkCountButton();
  checkResetButton();
}

void checkCountButton() {
  int reading = digitalRead(countButtonPin);

  if (reading != lastCountButtonState) {
    lastCountDebounceTime = millis();
  }

  if ((millis() - lastCountDebounceTime) > debounceDelay) {
    if (reading != countButtonState) {
      countButtonState = reading;

      if (countButtonState == LOW) {  // Button was just pressed
        counter++;
        Serial.print("Counter: ");
        Serial.println(counter);
      }
    }
  }

  lastCountButtonState = reading;
}

void checkResetButton() {
  int reading = digitalRead(resetButtonPin);

  if (reading != lastResetButtonState) {
    lastResetDebounceTime = millis();
  }

  if ((millis() - lastResetDebounceTime) > debounceDelay) {
    if (reading != resetButtonState) {
      resetButtonState = reading;

      if (resetButtonState == LOW) {
        counter = 0;
        Serial.println("=== COUNTER RESET ===");
        Serial.print("Counter: ");
        Serial.println(counter);
      }
    }
  }

  lastResetButtonState = reading;
}
