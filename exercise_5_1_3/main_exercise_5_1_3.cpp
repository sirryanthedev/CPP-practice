#include <iostream>
#include "exercise_5_1_3.h"

int main()
{
    coordinate point1{5, 4};
    point1.show_coordinate();

    std::cout << point1.distance_to(coordinate(2,3)) << std::endl; // distance between point1 and an rvalue temporary object

    return 0;
}