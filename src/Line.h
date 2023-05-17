#pragma once

#include "Point.h"
#include <string>

using std::string;

class Line
{
public:
    Line(float, float, float);
    Line(float, float);
    Line(Point, Point);
    float distanceFrom(Point p);
    float distanceFrom(Line l);

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

private:
    float m_a, m_b, m_c;
    //    ax + by = c

    float slope;
    float y_intercept, x_intercept;

    const Line* X_axis {0};
};