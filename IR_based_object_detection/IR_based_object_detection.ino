// Define the GPIO pins
#define IR_SENSOR_PIN 39 // IR sensor output connected to GPIO 18
#define LED_PIN 15       // LED connected to GPIO 23

// Variable to store the previous state of the sensor
bool previousState = HIGH; // Assume no object detected initially (HIGH)

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Initialize the IR sensor pin as input
  pinMode(IR_SENSOR_PIN, INPUT);

  // Initialize the LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Turn off the LED initially
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Read the value from the IR sensor
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  // Check if the IR sensor detects an object
  if (sensorValue == LOW && previousState != LOW) { // Object detected
    // Turn on the LED
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Object detected! LED is ON");
  } else if (sensorValue == HIGH && previousState != HIGH) { // No object detected
    // Turn off the LED
    digitalWrite(LED_PIN, LOW);
    Serial.println("No object detected. LED is OFF");
  }

  // Update the previous state
  previousState = sensorValue;

  // Small delay to stabilize the readings
  delay(100);
}
