

// constants won't change. They're used here to set pin numbers:
const int firstButtonPin = 2;  // the number of the pushbutton pin
const int ledPin = 11;    // the number of the LED pin
const int secondButtonPin = 3;

// variables will change:
int firstButtonState = 0;  // variable for reading the pushbutton status
int secondButtonState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize both buttons as an input:
  pinMode(firstButtonPin, INPUT);
  pinMode(secondButtonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  firstButtonState = digitalRead(firstButtonPin);
  secondButtonState = digitalRead(secondButtonPin);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (firstButtonState == LOW && secondButtonState == LOW) {
    // LED should be fully "ON" if both buttons are depressed
    analogWrite(ledPin, 255);
  } else if (firstButtonState == HIGH && secondButtonState == LOW) {
    // if first button is pressed, LED should be PWM'd to ~75%
    analogWrite(ledPin, 255 * 0.75);
  } else if (firstButtonState == LOW && secondButtonState == HIGH) {
    // if the second button is pressed, the PWM-regulated brightness is set to 50%
    analogWrite(ledPin, 255 * 0.5);
  } else {
    // if both are pressed, brightness is set to 25%
    analogWrite(ledPin, 255 * 0.25);
  }
}
