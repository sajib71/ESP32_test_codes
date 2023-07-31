// Follow the circuit diagram
// The LED turn ON only when the button is pressed and LED turn OFF when the push_button is release(normal state)
int button = 15; // digital pin 15 for push button
int led = 14; // digital pin 14 for led
int button_state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT); // GPIO 14 for Output
  pinMode (button,INPUT); // GPIO 15 for Input
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button); // Check push button status

  if(button_state == HIGH){ // using if condition check button status
    digitalWrite(led,HIGH); // Hight state led ON
  }
  else{
    digitalWrite(led,LOW); // else Low state led OFF
  }
}
