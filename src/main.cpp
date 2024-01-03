#include <Arduino.h>
#include "CircleTools.cpp"
#include <Servo.h>
#include <math.h>

// put function declarations here:
void printPointsOnCircle(Circle c, float degStep);
void setLaserState(bool);
void setLaserPosition(float, float);
float cAngle(float);
float aAngle(float);
char getSerialChar();

Servo cAxisServo;
Servo aAxisServo;

const int C_AXIS_CENTER = 1000;
const int A_AXIS_CENTER = 1200;
// Entfernung von der Wand in mm
const int DISTANCE = 740;

const float C_AXIS_TRANSLATION = 2.33f;
const float A_AXIS_TRANSLATION = 1.86f;
const int COMPENSATION = 721;

void setup() {
  Serial.begin(9600);

  setLaserState(false);
  // Laser
  pinMode(2, OUTPUT);

  // attach servos
  cAxisServo.attach(6);
  aAxisServo.attach(5);
  setLaserPosition(0,0);

  setLaserState(true);
  Serial.println("Ready");

}

void loop() {
  getSerialChar();
  setLaserPosition(0,50);
  getSerialChar();
  setLaserPosition(0,0);
}

char getSerialChar() {
    while(true) {
    if(Serial.available()) {
      return Serial.read();
    }
  }
}

void setLaserPosition(float x, float y) {
  float c = cAngle(x);
  float a = aAngle(y);
  Serial.println("c="+String(c)+", a="+String(a));
  cAxisServo.writeMicroseconds(round(C_AXIS_CENTER + c));
  aAxisServo.writeMicroseconds(round(A_AXIS_CENTER - a));
}

float aAngle(float yPos) {
  return(atan(yPos/DISTANCE)*COMPENSATION*A_AXIS_TRANSLATION);
}

float cAngle(float yPos) {
  return(atan(yPos/DISTANCE)*COMPENSATION*C_AXIS_TRANSLATION);
}

void setLaserState(bool val) {
  if(val) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

void printPointsOnCircle(Circle c, float degStep) {
    Serial.println("Circle with radius: "+String(c.getRadius()));
  for(int deg = 0 ; deg <= 360 ; deg += degStep) {
    Point p = c.getPointOnCircle(deg);
    Serial.println("Deg="+String(deg)+"°, x="+String(p.x)+", y="+p.y);
  }
}

// put function definitions here: