#include <cmath>
#include "Point.h"

Point::Point(float x, float y)
    : m_X{x}, m_Y{y} {}

string Point::toString() { return "( " + std::to_string(m_X) + ", " + std::to_string(m_Y) + " )"; }

Point Point::getOrigin() { return Point(0, 0); }

float Point::distanceFrom(Point p) const
{
    float a = std::abs(this->m_X - p.m_X);
    float b = std::abs(this->m_Y - p.m_Y);

    return (float)std::sqrt(a * a + b * b);
}

float Point::distanceTo(Point p) const { return distanceFrom(p); }

float Point::distanceFromOrigin() const { return distanceFrom(getOrigin()); }

float Point::getQuadrant() const
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

float Point::getX() const { return m_X; }

float Point::getY() const { return m_Y; }

std::ostream &operator<<(std::ostream &stream, Point p)
{
    stream << "(" << p.getX() << ", " << p.getY() << ")";
    return stream;
}
