/*
 * Project: Button-Controlled LED
 * Description:
 * Read a push button state to control an LED
 * 
 * Author: Sanaullah Sajib
 * Date: March 9, 2025
 */
int ledPin = 4;                       // LED connected to GPIO 4
int buttonPin = 35;                   // Button connected to GPIO 35
// int buttonState;                   // Stores the button state
bool buttonState = false;             // LED toggle state (ON/OFF)
bool lastButtonState = HIGH;          // Stores the previous button state

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);          // Use pull-up resistor
  pinMode(ledPin, OUTPUT);            // Use for Output
}

void loop() {
  // Read the state of the pushbutton value
  // buttonState = digitalRead(buttonPin); 
  bool currentButtonState = digitalRead(buttonPin);
  // Detect button press (only when transitioning from HIGH to LOW)
  if(lastButtonState == HIGH && currentButtonState == LOW){
    buttonState = !buttonState;       // Toggle LED state
    if(buttonState){
      digitalWrite(ledPin, HIGH);
      Serial.print("Button is Pressed: LED ON");
    } else{
      digitalWrite(ledPin, LOW);
      Serial.println("Button is not Pressed: LED OFF");
    }
    delay(200);  // Debounce delay
  }
  lastButtonState = currentButtonState;  // Update button state for next loop
}
