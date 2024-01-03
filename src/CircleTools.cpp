#include <Arduino.h>
#include <math.h>

using namespace std;

class Point
{
public:
    Point(float xPos, float yPos)
    {
        x = xPos;
        y = yPos;
    }
    float x;
    float y;
};

class Circle
{
public:
    Circle(float radius)
    {
        r = radius;
    }

    Point getPointOnCircle(float deg)
    {
        float xPos = cos(deg * (M_PI / 180)) * r;
        float yPos = sin(deg * (M_PI / 180)) * r;
        return Point(xPos, yPos);
    }

    float getRadius() {
        return r;
    }

    void setRadius(float radius) {
        r = radius;
    }

private:
    float r;
};