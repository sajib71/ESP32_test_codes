/*
 * Project Name : PWM_LedBreathing
 * 
 * Description:
 *   This project implements a PWM-based breathing effect 
 *   for multiple LEDs connected to an ESP32 or Arduino board. 
 *   The LEDs smoothly fade in and out to create a breathing effect using PWM (Pulse Width Modulation). The code utilizes an array to manage multiple LEDs, and each LED's brightness is dynamically adjusted in a loop to achieve the breathing effect.
 * 
 * Features:
 *   - PWM control for smooth LED dimming
 *   - Breathing effect for multiple LEDs
 *   - Configurable number of LEDs via array
 *   - Adjustable breathing speed
 *   
 * Hardware Requirements:
 *   - ESP32 / Arduino Board
 *   - Multiple LEDs connected to PWM-capable pins (e.g., 19, 21, etc.)
 *   - Resistors (1K)
 *   
 * Libraries Used:
 *   - None (Standard Arduino functions)
 * 
 * Author: Sanaullah Sajib
 * Date: April 8, 2025
 */

const int ledPins[] = {19, 21, 4};  // Add more pins if needed
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);  // Number of LEDs

int brightness = 0;   // LED brightness level
int fadeAmount = 1;   // Amount to fade the LED by

void setup() {
  // Set all LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Loop through each LED and apply the breathing effect
  for (int i = 0; i < numLeds; i++) {
    analogWrite(ledPins[i], brightness);  // Set the LED brightness

    // Change the brightness for the next cycle
    brightness = brightness + fadeAmount;

    // Reverse the direction of fading at the ends
    if (brightness <= 0 || brightness >= 128) {
      fadeAmount = -fadeAmount;
    }
  }

  delay(30);  // Control the breathing speed
}
