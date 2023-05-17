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

Line::Line(Point p1, Point p2)
{
    slope = calcSlope(p1, p2);
    y_intercept = p1.getY() - p1.getX()*slope;
    x_intercept = -y_intercept / slope;

    m_a = slope;
    m_b = -1;
    m_c = y_intercept;
}

float Line::distanceFrom(Point p)
{
    /*
    Formula :

    dist = (|ax0 + by0 + c|) / sqrt(a*a + b*b)
    */
    float numerator = std::abs(m_a*p.getX() + m_b*p.getY() + m_c);
    float denominator = std::sqrt(m_a*m_a + m_b*m_b);
    return numerator / denominator;
}

float Line::distanceFrom(Line l)
{
    if (slope == l.slope) {
        float numerator {std::abs(y_intercept - l.getY_intercept())};
        float denominator {std::sqrt(1 + slope*slope)};

        float result {numerator / denominator};
        return result;
    }
    return 0.0f;
}

float *Line::getValues()
{
    float* result = new float[3] {m_a, m_b, m_c};

    return result;
}

string Line::toString()
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);

    // ss << m_a << "X " << (m_b<0?"+ ":"- ") << std::abs(m_b) << "Y " << (m_c<0?"- ":"+ ") << std::abs(m_c) << " = 0";
    ss << Numbers::numPrint(m_a) << "X " << Numbers::numPrint(m_b) << "Y " << Numbers::numPrint(m_c) << " = 0";
    return ss.str();
}

string Line::toGeneralForm() { return toString(); }

string Line::toSlopeForm()
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);

    ss << "Y = " << slope << "X " << ((y_intercept < 0)?"- ":"+ ") << std::abs(y_intercept);
    return ss.str();
}

bool Line::ifPointExists(Point p) { return (m_a*p.getX() +  m_b*p.getY() + m_c == 0) ? true : false; }

bool Line::isParallelTo(Line l) { return (l.slope == slope) ? true : false; }

float Line::calcSlope(Line line) { return line.getSlope(); }

float Line::calcSlope(Point p1, Point p2)
{
    float m = (p1.getX() - p2.getX()) / (p1.getY() - p2.getY());
    return m;
}

float Line::getSlope() { return slope; }

float Line::getX_intercept() { return x_intercept; }

float Line::getY_intercept() { return y_intercept; }

Line Line::getX_axis() { return Line(0, 1, 0); }
Line Line::getY_axis() { return Line(1, 0, 0); }

Line Line::getLinefromPoints(Point p1, Point p2) { return Line(p1, p2); }

std::ostream &operator<<(std::ostream &stream, Line l)
{
    float *values = l.getValues();

    stream << *values << "X + " << *(values + 1) << "Y + " << *(values + 2) << " = 0";
    delete[] values;
    return stream;
}
