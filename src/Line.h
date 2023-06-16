#pragma once

#include "Point.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <ostream>

class Line {
private:
    // These are the values of the co-efficients of X, Y, and a constant that forms a line.
    float m_a, m_b, m_c;        // ax + by + c = 0
    // The slope private member of a line instance. No line would exist without the slope.
    float slope;
    // The X & Y intercept private member of a line instance. No line would exist without X & Y intercepts.
    float y_intercept, x_intercept;

    static const Line x_axis;

    static const Line y_axis;

public:
    /**
     * @breif
     * This is the basic constructor that a Line object can be instantiated. We need to pass 3 floating point values,
     * viz., the co-efficients of the X, Y and a constant which forms the mathematical equation aX + bY + C = 0.
     * @return Line instance
     */
    Line(float, float, float);

    // This constructor takes in 2 floating point values, which are the slope and the y_intercept of the
    // line, which are also enough for the construction of a line in real-time.
    Line(float, float);

    // Another way of forming a line, is just by joining the given 2 Points. Just pass the references to the Points.
    Line(const Point &point1, const Point &point2);

    // Copy Constructor
    Line(const Line&);

    /**
     * @brief This method returns a float value of distance from a point to a Line perpendicularly.
     * @param point : const Point reference.
     * @return perpendicular distance from the provided point, as a floating point decimal.
     * */
    [[nodiscard]] float distanceFrom(const Point &point) const;

    /**
     * @brief This method returns the perpendicular distance from the argument passed line object, if it is
     * only parallel to the current line as a floating point decimal value.
     * @param line : const Line reference.
     * @return perpendicular distance from the provided parallel line, as a floating point decimal.
     * */
    [[nodiscard]] float distanceFrom(const Line &line) const;

    [[nodiscard]] float * getValues() const;

    [[deprecated("Use the overloaded << operator, using `cout << line;`")]]
    // This method is completely deprecated.
    // But this printing the functionality object to console is
    // done by the operator<< overloading in the header file.
    // You can use operator<< without issues.
    std::string toString();

    [[deprecated("Use the overloaded << operator, using `cout << line;`")]]
    std::string toSlopeForm();   // We get the slope form of the line, unlike the above 2 methods.

    /**
     * @brief This method checks if the point exists on the Line or not, returns a bool.
     * @param point : const Point reference
     * @return boolean value if the provided point is on the current line.
     * */
    [[nodiscard]] bool ifPointExists(const Point &point) const;

    /**
     * @brief This method checks if the passed Line is parallel to our line, returns a bool.
     * @param line : const Line reference
     * @return boolean if the provided line reference is parallel to the current line.
     * */
    [[nodiscard]] bool isParallelTo(const Line &line) const;

    /**
     * @brief Calculate the slope of the passed Line reference, and return a floating point value.
     * @param line : const Line reference
     * @return slope of the line provided as a floating point decimal.
     * */
    float static calcSlope(const Line &line);

    // Calculate the slope of the line formed by the args (Point reference objects), and return a floating point value.
    float static calcSlope(const Point &point1, const Point &point2);


    // returns the slope as a floating value, which is a private member "slope".
    [[nodiscard]] float getSlope() const;

    // returns the Y-intercept as a floating value, which is a private member "y_intercept"
    [[nodiscard]] float getX_intercept() const;

    // returns the X-intercept as a floating value, which is a private member "x_intercept"
    [[nodiscard]] float getY_intercept() const;


    // Returns a line instance of X-axis.
    const static Line & getX_axis();

    // Returns a line instance of Y-axis.
    const static Line & getY_axis();

    // Returns a line instance which is formed by joining the given 2 Point references.
    Line static getLineFromPoints(const Point &point1, const Point &point2);
};

// To print the Line instance to console which looks like a mathematical equation.
std::ostream &operator<<(std::ostream &, const Line &);
