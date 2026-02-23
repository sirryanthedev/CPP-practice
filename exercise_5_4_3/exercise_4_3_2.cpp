#include "exercise_4_3_2.h"
#include <iostream>

int Date::get_day() const
{
    return m_day;
}

int Date::get_month() const
{
    return m_month;
}

int Date::get_year() const
{
    return m_year;
}

void Date::set_day(int day)
{
    m_day = day;
}

void Date::set_month(int month)
{
    m_month = month;
}

void Date::set_year(int year)
{
    m_year = year;
}

void Date::print_full_date() const
{
    std::cout << "date: " << m_year << "/" << m_month << "/" << m_day << std::endl;   
}

// constructors
Date::Date() : m_day{1}, m_month{1}, m_year{1}
{
    std::cout << "default constructor called implicitly\n";
}
Date::Date(int day, int month, int year) : m_day{day}, m_month{month}, m_year{year}
{
    std::cout << "custom constructor called implicitly\n";
}