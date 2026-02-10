#include "exercise_4_2_2.h"
#include <iostream>

int main()
{
    Date this_year{}; // init an object of type Date
    this_year.set_day(3); // set day of this_year to 3

    std::cout << this_year.get_day(); // output day of this year (3) 

    return 0;
}