#pragma once

#include "Point.h"
#include "Numbers.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <ostream>

using std::string;

class Line
{
private:
    float m_a, m_b, m_c;        // ax + by = c
    float slope;
    float y_intercept, x_intercept;
public:
    Line(float, float, float);
    Line(float, float);
    Line(Point, Point);
    float distanceFrom(Point p);
    float distanceFrom(Line l);

    float* getValues();

    string toString();
    string toGeneralForm();
    string toSlopeForm();

    bool ifPointExists(Point);
    bool isParallelTo(Line);

    float static calcSlope(Line);
    float static calcSlope(Point, Point);

    float getSlope();
    float getX_intercept();
    float getY_intercept();

    Line static getX_axis();
    Line static getY_axis();
    Line static getLinefromPoints(Point, Point);
};

std::ostream& operator<<(std::ostream& , Line);
