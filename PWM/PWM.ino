/*
 * Project: PWM LED Brightness Control with Potentiometer
 * 
 * Description:
 * Controls LED brightness using a potentiometer. The analog value from A0 is mapped to PWM (0–255)
 * and sent to pin 9 to adjust the LED brightness.
 * 
 * Components:
 * - Arduino, 10k Pot, LED, 220Ω Resistor
 * 
 * Author: Sanaullah Sajib
 * Date: April 7, 2025
 */

const int potPin = A0;     // Potentiometer connected to analog pin A0
const int ledPin = 9;      // LED connected to digital PWM pin 9

int potValue = 0;          // Variable to store potentiometer reading (0 to 1023)
int pwmValue = 0;          // Mapped value for PWM (0 to 255)

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  potValue = analogRead(potPin);              // Read analog value from potentiometer (0-1023)
  pwmValue = map(potValue, 0, 1023, 0, 255);  // Convert to PWM range (0-255)
  
  analogWrite(ledPin, pwmValue);              // Set LED brightness

  delay(10);  // Small delay to stabilize reading (optional)
}
