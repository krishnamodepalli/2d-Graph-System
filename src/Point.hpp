#pragma once

#include <string>
#include <ostream>

class Point {
private:
    float m_X, m_Y;

    // This static Point Origin is a constant so that any other program cannot change it, and we
    // use it to pass a reference to this Point, whenever a program is needed an Origin Point.
    const static Point Origin;

public:
    // The only one way of constructing a Point object, given with 2 floating point decimal values, which
    // will be indicating as abscissa & ordinate.
    Point(float, float);
    // The params of the constructor are not references, this is because the author is willing to make the
    // construction of the Point object to be as simple & easy, like `Point (1, 3);`

    // Copy Constructor
    Point(const Point &);

    [[deprecated("Consider using the overloaded << operator to directly print"
    "the Point object.")]]
    // toString method to produce a string literal for the mathematical representation of the Point.
    std::string toString();


    // This static method is used to return the static Origin Point object, whose abscissa and ordinates
    // (X, Y) are set to (0, 0).
    const static Point& getOrigin();


    /**
     * @brief Calculate the distance from the given const Point object reference to "this" (our Point) object in
     * default units as a floating point decimal.
     * @param point : const Point reference.
     * */
    float distanceFrom(const Point &point) const;

    /**
     * @brief Calculate the distance from the given const Point object reference to "this" (our Point)
     * object in default units as a floating point decimal.
     * @param point : const Point reference.
     * */
    float distanceTo(const Point &point) const;

    /**
     * @brief Calculate the distance from the Origin to "this"(Our Point) object in default units as a floating
     * point decimal.
     * */
    float distanceFromOrigin() const;

    /**
     * @brief This method returns the Quadrant of "this" Point object, as a short integer.
     * @return A short, indicating the quadrant. This do return -1 if the Point is not a valid one,
     * or in case of any error. Usually, this is not excepted, as far as the author trails,
     * this doesn't happen & he doesn't want it to happen.
     */
    short getQuadrant() const;

    float getX() const;     /// Returns the abscissa of the current Point object.
    float getY() const;     /// Returns the ordinate of the current Point object.
};

/**
 * @brief Make sures that we can directly print the line instance to the console, with the help
 * of operator<< overloading.
 * @return ostream &stream
 */
std::ostream &operator<<(std::ostream &, const Point &);
