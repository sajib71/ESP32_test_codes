// The built-in LED is connected to GPIO pin 2.
// This LED can be controlled by setting the GPIO pin HIGH to turn it on and LOW to turn it off.

int LED_BUILTIN = 2; // Blink built in led (Pin declaration)
void setup() {
  // put your setup code here, to run once:
  pinMode (LED_BUILTIN, OUTPUT); // Output declaration
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (LED_BUILTIN, HIGH); // HIGH to turn it ON.
  delay (500);
  digitalWrite (LED_BUILTIN, LOW); // LOW to turn it OFF
  delay (500);
}
