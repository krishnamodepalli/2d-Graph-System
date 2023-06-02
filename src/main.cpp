#include "Point.h"
#include "Line.h"
#include <iostream>


// This is a sample program to let you know how to use the project.
// There are more explained examples and usages in Usage.md file.
int main()
{
    Point point(3.0f, 4.0f);
    std::cout << point.distanceFromOrigin() << '\n';

    return 0;
}
