#include "Point.h"
#include "Line.h"
#include <iostream>


// This is a sample program to let you know how to use the project.
// There are more explained examples and usages in Usage.md file.
int main()
{
    std::cout << Line(0., 1.3, 0) << '\n';
    std::cout << Line(1, 8) << '\n';
    std::cout << Line(1.2, 0., -119) << '\n';

    return 0;
}
