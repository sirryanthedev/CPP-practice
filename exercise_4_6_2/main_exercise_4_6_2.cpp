#include "exercise_4_6_2.h"

#include <iostream>

int main()
{
    Date this_year{}; // create an initialised (through default constructor) instance of date
    this_year.print_full_date(); // default date: 0001/01/01 yyyy/mm/dd
    
    Date that_year(10, 2, 2026); // new object, custom constructor called implicitly at creation
    that_year.print_full_date(); // date: 2026/02/10

    Date another_year("22/12/2025");
    another_year.print_full_date(); // date: 2025/12/22

    return 0;
}