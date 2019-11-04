#include <ESP32Servo.h>
#include <Stepper.h>
#include <arduino.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

const int stepsPerRevolution = 64;
Stepper myStepper(stepsPerRevolution, 32, 33, 25, 26);
Stepper myStepper2(stepsPerRevolution, 15, 2, 0, 4);

int servoPos = 0;    // variable to store the servo position
int degree = 0;
int rotationCounter = 0;
bool moveForward = true;
int increment = 10;
int prevprevSensorVal = 0;
int prevSensorVal = 0;
int sensorVal = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object
  myservo2.attach(12);
  myStepper.setSpeed(300);
  myStepper2.setSpeed(300);

  myservo.write(135); // right wing 
  myservo2.write(45); // left wing 

  pinMode(34, INPUT);
}


void loop() {
  prevprevSensorVal = prevSensorVal;
  prevSensorVal = sensorVal;
  sensorVal = analogRead(34);

  // Had to add extra logic to deal with problems in reading sensor value
  if (sensorVal == 0 && prevSensorVal == 0 && prevprevSensorVal == 0) {
  
    myStepper.step(stepsPerRevolution);
    myStepper2.step(stepsPerRevolution);
    rotationCounter += stepsPerRevolution;
  
    rotate10();
  }
}

void rotate10() {

  // limit Servo movement from 0-90 degrees 
  if (servoPos == 90)
    moveForward = false;
  if (servoPos == 0 )
    moveForward = true;

  if (moveForward)
    servoPos += 5;
  else
    servoPos -= 5;

  // Change from linear to cosine interpolation 
  float cosVal = cos(myMap(servoPos, 0.0, 90.0, 0.0, M_PI));
  float interpolatedVal = myMap(cosVal, -1.0, 1.0, 0.0, 90.0);
  myservo2.write(interpolatedVal);
  myservo.write(90-interpolatedVal);
}

// Map function for floats 
float myMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return ((float)x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
