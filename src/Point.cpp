#include <cmath>
#include "Point.hpp"

Point::Point(float x, float y)
    : m_X{x}, m_Y{y} {}

const Point Point::Origin {0.0f, 0.0f};

std::string Point::toString() { return "( " + std::to_string(m_X) + ", " + std::to_string(m_Y) + " )"; }

const Point& Point::getOrigin() { return Origin; }

float Point::distanceFrom(const Point &point) const {
    float a = std::abs(this->m_X - point.m_X);
    float b = std::abs(this->m_Y - point.m_Y);

    return (float)std::sqrt(a * a + b * b);
}

float Point::distanceTo(const Point &point) const { return distanceFrom(point); }

float Point::distanceFromOrigin() const { return distanceFrom(getOrigin()); }

short Point::getQuadrant() const {
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

std::ostream &operator<<(std::ostream &stream, const Point &point) {
    stream << "(" << point.getX() << ", " << point.getY() << ")";
    return stream;
}
