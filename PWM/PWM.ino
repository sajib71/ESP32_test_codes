/*
 * Project Title: PWM LED Brightness Control using Potentiometer (ESP32)
 * 
 * Description:
 * This code controls the brightness of an LED using a potentiometer with an ESP32. 
 * The potentiometer's analog value is read, mapped to a PWM range (0-255), and used to adjust 
 * the LED brightness. The LED is connected to GPIO18, and the potentiometer to GPIO34.
 * 
 * Author: Sanaullah Sajib
 * Date: April 7, 2025
 */
 
const int potPin = 39;     // Potentiometer connected to GPIO34
const int ledPin = 4;     // LED connected to GPIO18

int potValue = 0;          // Potentiometer value
int pwmValue = 0;          // Mapped PWM value

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  potValue = analogRead(potPin);              // Read potentiometer value
  pwmValue = map(potValue, 0, 1023, 0, 255);  // Map to PWM range
  analogWrite(ledPin, pwmValue);              // Set LED brightness
  delay(10);  // Optional delay
}
