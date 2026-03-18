#include "exercise_7_3_2.h"
#include <iostream>
// #include <cstdlib>

// destructor
Vector::~Vector()
{
    std::cout << "Destructor called for instance of Vector" << std::endl;
    free(m_elements);
}

// methods
void Vector::add_element(double element)
{   
    // no elements
    if (m_nelements == 0)
    {
        double* temp = (double*)malloc(sizeof(double));

        // check for memory allocation failure
        if (!temp)
        {
            std::cout << "Memory allocation failed" << std::endl;
            exit(1);
        }

        else
        {
            std::cout << "The first element will be added" << std::endl;
            m_elements = temp;
        }
    }

    // m_elements not empty in other words m_nelements > 0
    else
    {
        double* temp = (double*)realloc(m_elements, (m_nelements + 1) * sizeof(double));

         // check for memory allocation failure
        if (!temp)
        {
            std::cout << "Memory allocation failed" << std::endl;
            exit(2);
        }

        else
        {
            m_elements = temp;
        }
    } 

    // increment number of elements
    m_nelements++;

    // insert element into elements
    m_elements[m_nelements - 1] = element;
}

void Vector::print_elements() const
{
    // case no elements
    if (m_nelements == 0)
    {
        std::cout << "There is nothing to print" << std::endl;
    }

    else
    {
        for (size_t i = 0; i < m_nelements; i++)
        {
            std::cout << m_elements[i] << std::endl;
        }
    }
}