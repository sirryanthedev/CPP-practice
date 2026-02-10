#include "exercise_4_3_2.h"
#include <iostream>

int main()
{
    Date this_year{}; // create an initialised (through default constructor) instance of date
    this_year.print_full_date(); // date: 1/1/1
    
    Date that_year(10, 2, 2026); // new object, custom constructor called implicitly at creation
    that_year.print_full_date(); // date: 2026/2/10

    return 0;
}