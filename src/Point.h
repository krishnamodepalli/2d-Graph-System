#pragma once

#include <string>
using std::string;

class Point
{
private:
    float m_X, m_Y;

public:
    Point(float, float);
    string toString();

    Point static getOrigin();

    float distanceFrom(Point p);
    float distanceTo(Point p);
    float distanceFromOrigin();
    float getQuadrant();

    float getX();
    float getY();
};
