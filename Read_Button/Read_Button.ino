/*
 * Project: Button-Controlled LED
 * Description:
 * Read a push button state to control an LED
 * 
 * Author: Sanaullah Sajib
 * Date: March 9, 2025
 */
int ledPin = 4;                      // LED connected to GPIO 4
int buttonPin = 35;                  // Button connected to GPIO 35
int buttonState;                     // Toggle state

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);         // Use pull-up resistor
  pinMode(ledPin, OUTPUT);           // Use for Output
}

void loop() {
  // Read the state of the pushbutton value
  buttonState = digitalRead(buttonPin); 
  // Detect button press (only when transitioning from HIGH to LOW)
  if(buttonState == LOW){
    digitalWrite(ledPin, HIGH);     // Turn ON the led
    Serial.println("Button is Pressed");
  } else {
    digitalWrite(ledPin, LOW);      // Turn OFF the led
    Serial.println("Button is not Pressed");
  }
  delay(50);  // Delay to reduce rapid polling and debounce the button
}
