#include <iostream>
#include <cmath>
#include "exercise_5_1_3.h"

coordinate::coordinate() : m_x{}, m_y{}
{
    std::cout << "Default constructor called" << std::endl;
}

coordinate::coordinate(int a, int b) : m_x{a}, m_y{b}
{
    std::cout << "Custom constructor called" << std::endl;
}

int coordinate::get_x() const
{
    return m_x;
}

int coordinate::get_y() const
{
    return m_y;
}

void coordinate::set_x(int a)
{
    m_x = a;
}

void coordinate::set_y(int b)
{
    m_y = b;
}

void coordinate::show_coordinate() const
{
    std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
}

double coordinate::distance_to(coordinate&& other) const
{
    return std::sqrt(std::pow((m_x - other.m_x), 2) + std::pow((m_y - other.m_y), 2));
}