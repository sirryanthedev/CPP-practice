#include "exercise_4_2_2.h"

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