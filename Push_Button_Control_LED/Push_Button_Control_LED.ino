/*
 * ESP32 Button Controlled LED
 * This program demonstrates how to control an LED using a push button.
 * The LED turns ON when the button is pressed and turns OFF when the button is released.
 * 
 * Hardware Requirements:
 * - ESP32 Development Board
 * - Push Button
 * - LED
 * 
 * Circuit Connection:
 * - Button connected to GPIO 15 (input)
 * - LED connected to GPIO 14 (output)
 * 
 * Date: 04 February 2024
 * Author: Sanaullah Sajib
 */
 
int button = 15;                      // digital pin 15 for push button
int led = 14;                         // digital pin 14 for led
int button_state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT);               // GPIO 14 for Output
  pinMode (button,INPUT);             // GPIO 15 for Input
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button); // Check push button status

  if(button_state == HIGH){           // using if condition check button status
    digitalWrite(led,HIGH);           // Hight state led ON
  }
  else{
    digitalWrite(led,LOW);            // else Low state led OFF
  }
}
