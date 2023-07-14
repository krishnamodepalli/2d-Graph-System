#include <cmath>
#include "Point.hpp"

Point::Point(float x, float y)
    : m_X{x}, m_Y{y} {}

const Point Point::Origin {0.0f, 0.0f};

Point::Point(const Point &point) {
    this->m_X = point.getX();
    this->m_Y = point.getY();
}

std::string Point::toString() { return "( " + std::to_string(m_X) + ", " + std::to_string(m_Y) + " )"; }

const Point& Point::getOrigin() { return Origin; }

float Point::distanceFrom(const Point &point) const {
    float a = std::abs(this->m_X - point.m_X);
    float b = std::abs(this->m_Y - point.m_Y);

    return (float)std::sqrt(a * a + b * b);
}

float Point::distanceTo(const Point &point) const { return distanceFrom(point);}

float Point::distanceFromOrigin() const { return distanceFrom(getOrigin()); }

Point Point::mid_point(Point &p1, Point &p2) { return (p1 + p2) / 2; }

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

Point Point::operator+(const Point &point) {
    return { m_X + point.getX(), m_Y + point.getY()};
}

Point Point::operator-(const Point &point) {
    return { m_X - point.getX(), m_Y - point.getY()};
}

Point Point::operator*(float factor) { return { m_X * factor, m_Y * factor}; }

Point Point::operator/(float factor) { return { m_X / factor, m_Y / factor}; }

std::ostream &operator<<(std::ostream &stream, const Point &point) {
    stream << "(" << point.getX() << ", " << point.getY() << ")";
    return stream;
}
