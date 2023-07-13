#include "Point.hpp"
#include "Line.hpp"
#include <iostream>

// This is a sample program to let you know how to use the project.
// There are more explained examples and usages in Usage.md file.
int main()
{
    Line a(3, -1, -3);
    Line b(2.3, -1, 4);

    std::cout << a.getIntersectionPoint(b) << std::endl;

    return 0;
}
