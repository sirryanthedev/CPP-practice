#include "exercise_4_5_2.h"
#include <iostream>

void Stack::print_stack() const
{
    for (int i = 0; i <= m_top; i++){
        std::cout << m_elems[i] << ' ';
    }
}

void Stack::init_stack()
{
    m_top = -1;
}

void Stack::push(char c)
{
    if (!is_full())
    {
        m_top++;
        m_elems[m_top] = c;
        return;
    }
    
    std::cerr << "The stack is full!\n";
}

char Stack::pop()
{
    if (!is_empty())
    {
        auto temp = m_elems[m_top];
        m_top--;
        return temp;
    }

    std::cerr << "The stack is empty, there is nothing to pop!\n";
    return '\0';
}

bool Stack::is_empty() const
{
    return m_top == -1;
}

bool Stack::is_full() const
{
    return m_top == m_capacity - 1;
}

// default constructor
Stack::Stack(int size) : m_elems{new char[size]}, m_capacity{size}
{
    std::cout << "The default constructor was called for the stack!\n";
}

// destructor
Stack::~Stack()
{
    std::cout << "The destructor was called for the stack!\n";
    delete[] m_elems;
}