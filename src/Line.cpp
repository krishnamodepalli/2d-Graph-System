#include "Line.h"

Line::Line(float a, float b, float c)
    :m_a{a}, m_b{b}, m_c{c}
{
    slope = - m_a / m_b;
    y_intercept = - m_c / m_b;
    x_intercept = - m_c / m_a;
}

Line::Line(float m, float c)    // m: slope, c: y_intercept
    : m_a{m}, m_b{-1}, m_c{c}
{
    slope = m;
    y_intercept = c;
    x_intercept = -c / m;
}

Line::Line(const Point &point1, const Point &point2) {
    slope = calcSlope(point1, point2);
    y_intercept = point1.getY() - point1.getX() * slope;
    x_intercept = -y_intercept / slope;

    m_a = slope;
    m_b = -1;
    m_c = y_intercept;
}

const Line Line::x_axis {0.0f, 1.0f, 0.0f};

const Line Line::y_axis {1.0f, 0.0f, 0.0f};

float Line::distanceFrom(const Point& point) const {
    /*
    Formula :

    dist = (|ax0 + by0 + c|) / sqrt(a*a + b*b)
    */
    float numerator = std::abs(m_a * point.getX() + m_b * point.getY() + m_c);
    float denominator = std::sqrt(m_a*m_a + m_b*m_b);
    return numerator / denominator;
}

float Line::distanceFrom(const Line& line) const {
    if (slope == line.slope) {
        float numerator {std::abs(y_intercept - line.getY_intercept())};
        float denominator {std::sqrt(1 + slope*slope)};

        float result {numerator / denominator};
        return result;
    }
    return 0.0f;
}

float * Line::getValues() const {
    float* result = new float[3] {m_a, m_b, m_c};

    return result;
}

std::string Line::toString() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);

     ss << m_a << "X " << (m_b<0?"+ ":"- ") << std::abs(m_b) << "Y " << (m_c<0?"- ":"+ ") << std::abs(m_c) << " = 0";
//    ss << Numbers::numPrint(m_a) << "X " << Numbers::numPrint(m_b) << "Y " << Numbers::numPrint(m_c) << " = 0";
    return ss.str();
}

std::string Line::toGeneralForm() { return toString(); }

std::string Line::toSlopeForm() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);

    ss << "Y = " << slope << "X " << ((y_intercept < 0)?"- ":"+ ") << std::abs(y_intercept);
    return ss.str();
}

bool Line::ifPointExists(const Point& point) const { return (m_a * point.getX() + m_b * point.getY() + m_c == 0); }

bool Line::isParallelTo(const Line& line) const { return (line.slope == slope); }

float Line::calcSlope(const Line &line) { return line.getSlope(); }

float Line::calcSlope(const Point& point1, const Point& point2) {
    float m = (point1.getX() - point2.getX()) / (point1.getY() - point2.getY());
    return m;
}

// returns the slope of the line object.
float Line::getSlope() const { return slope; }

float Line::getX_intercept() const { return x_intercept; }

float Line::getY_intercept() const { return y_intercept; }

const Line & Line::getX_axis() { return x_axis; }
const Line & Line::getY_axis() { return y_axis; }

Line Line::getLineFromPoints(const Point& point1, const Point& point2) { return {point1, point2}; }

std::ostream &operator<<(std::ostream &stream, const Line &line) {
    float *values = line.getValues();

    stream << *values << "X + " << *(values + 1) << "Y + " << *(values + 2) << " = 0";
    delete[] values;
    return stream;
}
