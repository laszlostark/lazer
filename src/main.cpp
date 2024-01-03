#include <Arduino.h>
#include "CircleTools.cpp"

// put function declarations here:
void printPointsOnCircle(Circle c, float degStep);

void setup() {
  Serial.begin(9600);
  Circle c = Circle(10);
  printPointsOnCircle(c, 10);
}

void loop() {

}

void printPointsOnCircle(Circle c, float degStep) {
    Serial.println("Circle with radius: "+String(c.getRadius()));
  for(int deg = 0 ; deg <= 360 ; deg += degStep) {
    Point p = c.getPointOnCircle(deg);
    Serial.println("Deg="+String(deg)+"°, x="+String(p.x)+", y="+p.y);
  }
}

// put function definitions here: