/*
  Battery Voltage Monitoring with Smoothing
  Author: Sana Ullah Sajib
  Date: 30th November 2024
  Description:
  This program reads the battery voltage using ESP32's ADC pin (34),
  smooths the readings by averaging the last 10 ADC values, and calculates
  the corresponding battery percentage. The voltage is calibrated and
  printed to the Serial Monitor with a percentage based on a 3.3V to 4.2V range.

  The program uses:
  - 10 samples for smoothing (running average)
  - Calibration factor for voltage adjustment
  - Voltage range from 3.3V (min) to 4.2V (max) for battery percentage calculation
*/
const int numReadings = 10;             // Number of samples for averaging
int readings[numReadings];              // Array to store ADC readings
int readIndex = 0;                      // Index for current reading in the array
int total = 0;                          // Running total of the readings
int average = 0;                        // Average of the readings

const int inputPin = 34;                // ADC pin for battery voltage

// Battery and calibration constants
const float minVoltage = 3.3;           // Minimum battery voltage
const float maxVoltage = 4.2;           // Maximum battery voltage
const float calibrationFactor = 1.15;   // Calibration factor for voltage adjustment

void setup() {
  Serial.begin(115200);                 // Start serial communication at 115200 baud
  pinMode(inputPin, INPUT);             // Set pin 34 as input
  
  // Initialize all readings to 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Step 1: Remove the oldest reading from the total
  total = total - readings[readIndex];

  // Step 2: Read the current ADC value and store it in the array
  readings[readIndex] = analogRead(inputPin);

  // Step 3: Add the new reading to the total
  total = total + readings[readIndex];

  // Step 4: Advance to the next index in the array
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;                      // Wrap around to the start of the array
  }

  // Step 5: Calculate the average of the readings
  average = total / numReadings;

  // Step 6: Convert the average ADC value to voltage (assuming 5V input range)
  float voltage = (average / 4095.0) * 5;

  // Step 7: Apply calibration factor
  voltage *= calibrationFactor;

  // Step 8: Calculate battery percentage
  float percentage = ((voltage - minVoltage) / (maxVoltage - minVoltage)) * 100;
  if (voltage <= minVoltage) {
    percentage = 0;                     // Voltage below minVoltage is 0%
  } else if (voltage >= maxVoltage) {
    percentage = 100;                   // Voltage above maxVoltage is 100%
  }

  // Step 9: Print voltage and battery percentage to the Serial Monitor
  Serial.print("Battery Voltage: ");
  Serial.print(voltage, 2);             // Print voltage with 2 decimal places
  Serial.println(" V");

  Serial.print("Battery Percentage: ");
  Serial.print(percentage);          // Print percentage with 1 decimal place
  Serial.println(" %");

  delay(1000);                         // Delay 1 second before reading again
}
