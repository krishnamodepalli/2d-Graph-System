#pragma once

#include <string>
#include <ostream>
using std::string;

class Point
{
private:
    float m_X, m_Y;

public:
    Point(float, float);
    string toString();

    Point static getOrigin();

    float distanceFrom(Point p) const;
    float distanceTo(Point p) const;
    float distanceFromOrigin() const;
    float getQuadrant() const;

    float getX() const;
    float getY() const;
};

std::ostream& operator<<(std::ostream &, Point);
