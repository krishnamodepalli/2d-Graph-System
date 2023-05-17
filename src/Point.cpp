#include <cmath>
#include "Point.h"

Point::Point(float x, float y)
{
    m_X = x;
    m_Y = y;
}

string Point::toString() { return "( " + std::to_string(m_X) + ", " + std::to_string(m_Y) + " )"; }

Point Point::getOrigin() { return Point(0, 0); }

float Point::distanceFrom(Point p)
{
    float a = std::abs(this->m_X - p.m_X);
    float b = std::abs(this->m_Y - p.m_Y);

    return (float)std::sqrt(a * a + b * b);
}

float Point::distanceTo(Point p) { return distanceFrom(p); }

float Point::distanceFromOrigin() { return distanceFrom(getOrigin()); }

float Point::getQuadrant()
{
    if (m_X > 0) {
        if (m_Y > 0)
            return 1;
        else if (m_Y < 0)
            return 4;
    } else {
        if (m_Y > 0)
            return 2;
        else if (m_Y < 0)
            return 3;
    } return -1;
}

float Point::getX() { return m_X; }

float Point::getY() { return m_Y; }
