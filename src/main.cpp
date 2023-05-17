#include "Point.h"
#include "Line.h"
#include <iostream>


// This is a sample program to let you know how to use the project.
// There are more explained exmaples and usages in Usage.md file.
int main()
{
    Line l1(3, 8);
    Line l2(3, 1);

    std::cout << "Distance bwtween two parallel lines l1 & l2 is : " << l1.distanceFrom(l2) << " units." << std::endl;
    std::cout << l1.isParallelTo(l2) << std::endl;


    return 0;
}
