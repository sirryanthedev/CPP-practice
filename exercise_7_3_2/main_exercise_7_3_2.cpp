#include "exercise_7_3_2.h"
#include <iostream>

int main()
{
    Vector vector{};
    vector.print_elements(); // no elements

    std::cout << std::endl;
    
    vector.add_element(3.1415926);
    vector.print_elements();

    std::cout << std::endl;

    vector.add_element(10.123);
    vector.print_elements();

    return 0;
}