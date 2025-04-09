/*
 * Safe version for ESP32
 * Name: Sanaullah Sajib
 */
int timer = 100;

// Define usable GPIO pins (avoid 6-11)
const int ledPins[] = {19, 21}; // Add more if needed
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Forward loop
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(timer);
    digitalWrite(ledPins[i], LOW);
  }

  // Reverse loop
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(timer);
    digitalWrite(ledPins[i], LOW);
  }
}
