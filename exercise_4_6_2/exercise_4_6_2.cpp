#include "exercise_4_6_2.h"

#include <iostream>
#include <string>
#include <iomanip>

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

void Date::print_full_date() const // output date (yyyy/mm/dd)
{
    std::cout << "date: " << std::setw(4) << std::setfill('0') << m_year << "/" 
    << std::setw(2) << std::setfill('0') << m_month << "/" 
    << std::setw(2) << std::setfill('0') << m_day << std::endl;   
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
Date::Date(std::string date_dmy) :  m_day{std::stoi(date_dmy.substr(0,2))}, 
                                    m_month{std::stoi(date_dmy.substr(3,2))}, 
                                    m_year{std::stoi(date_dmy.substr(6,4))}
{
    std::cout << "Day, month and year were extracted from the string succesfully\n";
} 