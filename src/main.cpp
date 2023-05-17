#include "Point.h"
#include "Line.h"
#include <iostream>


// This is a sample program to let you know how to use the project.
// There are more explained exmaples and usages in Usage.md file.
int main()
{
    Point p1 = Point(6, 8);
    Point origin = Point::getOrigin();

    std::cout << p1.distanceTo(origin) << std::endl;

    return 0;
}
