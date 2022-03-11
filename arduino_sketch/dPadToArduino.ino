// This is a test sketch to practice connecting a python script to the arduino
// Serial docs here: https://www.arduino.cc/reference/en/language/functions/communication/serial/readstring/
// Do not connect anything to pins 0 or 1 when using Serial. That can mess things up apparently.

// This is modified from the arduino tutorial

String pythonInputString; // This holds the string sent by the python script
int pythonInputInt;

// I know there are different enums in the python file and this is confusing
const int UP = 8; // The pin connected to the 'up' led
const int RIGHT = 2;  // The pin connected to the 'right' led
const int DOWN = 4; // The pin connected to the 'down' led
const int LEFT = 6; // The pin connected to the 'left' led

// These numbers aren't connected to pins, but they tell us when a
// Keyboard key was release in the python script
const int RELEASE = 0;

void setup() {
 // Set up the port that we use to communicate with the python script
 Serial.begin(9600);
 Serial.setTimeout(.1);

 // Set LEDs to output
 pinMode(UP, OUTPUT);
 pinMode(RIGHT, OUTPUT);
 pinMode(DOWN, OUTPUT);
 pinMode(LEFT, OUTPUT);

 // Light up all the lights for so I know it's working
 digitalWrite(UP, HIGH);
 digitalWrite(RIGHT, HIGH);
 digitalWrite(DOWN, HIGH);
 digitalWrite(LEFT, HIGH);
 delay(2000);
 digitalWrite(UP, LOW);
 digitalWrite(RIGHT, LOW);
 digitalWrite(DOWN, LOW);
 digitalWrite(LEFT, LOW);
}

void loop() {
 // I'm commenting this out to see if I can get continuous input
 while (!Serial.available());
 // Get python input and convert int to compare to enums
 pythonInputString = Serial.readString();
 pythonInputInt = pythonInputString.toInt();
 
 // Could have been a switch statement, but
 // This changes the LED pin output based on python input
 if (pythonInputInt == UP) {
  digitalWrite(UP, HIGH);
 } else if (pythonInputInt == RIGHT) {
  digitalWrite(RIGHT, HIGH);
 } else if (pythonInputInt == DOWN) {
  digitalWrite(DOWN, HIGH);
 } else if (pythonInputInt == LEFT) {
  digitalWrite(LEFT, HIGH);
 } else if (pythonInputInt == RELEASE) {
  digitalWrite(UP, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(DOWN, LOW);
  digitalWrite(LEFT, LOW);
 }
}
