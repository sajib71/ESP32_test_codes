// Define the pins
const int latchPin = 4; // Pin used for the latch circuit
const int ledPin = 5;   // Pin used for the LED (change as needed)

void setup() {
  // Initialize the latch and LED pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Set the latch pin high
  digitalWrite(latchPin, HIGH);

  // Turn on the LED
  digitalWrite(ledPin, HIGH);

  // Perform other initial setup tasks
  Serial.begin(115200);
  Serial.println("ESP32 is powered on, latch is enabled, and LED is on.");
}

void loop() {
  // Main code to execute after the latch and LED are set
  Serial.println("Device is running...");
  delay(1000); // Replace with your actual tasks
}
