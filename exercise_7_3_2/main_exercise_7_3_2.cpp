#include "exercise_7_3_2.h"
#include <iostream>

int main()
{
    Vector vector{};
    vector.print_elements(); // no elements

    std::cout << "----------------------\n";
    std::cout << std::endl;
    
    vector.add_element(3.1415926);
    vector.print_elements();

    std::cout << "----------------------" << std::endl;

    vector.add_element(10.123);
    vector.print_elements();

    std::cout << "----------------------\n";

    auto item{vector[0]};
    std::cout << item << std::endl;
    vector[0] = 8;
    item = vector[0];
    std::cout << item << std::endl;
    
    return 0;
}