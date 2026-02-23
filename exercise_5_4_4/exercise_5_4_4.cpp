#include "exercise_5_4_4.h"
#include <iostream>
#include <string>

// constructors for Racer
Racer::Racer()
{
    std::cout << "Default constructor called for a Racer object" << std::endl;
}

Racer::Racer(std::string name, std::string sex, Date birthdate, std::string team) : m_name{name}, m_sex{sex}, m_birthdate{birthdate}, m_team{team}
{
    std::cout << "Custom constructor called for a Racer object" << std::endl;
}

// getters for Racer
std::string Racer::get_name() const
{
    return m_name;
}

std::string Racer::get_sex() const
{
    return m_sex;
}

void Racer::get_birthdate() const
{
    std::cout << "birthdate: " 
    << m_birthdate.get_year()
    << '/' << m_birthdate.get_month() 
    << '/' << m_birthdate.get_day() 
    << std::endl;
}

std::string Racer::get_team() const
{
    return m_team;
}

void Racer::view_Cars() const
{
    int number{};
    for (const auto& car : m_cars)
    {
        std::cout << "Info car N" << ++number << ":" << std::endl
        << "Brand: " << car.get_brand() << std::endl
        << "Pilot: " << car.get_pilot() << std::endl
        << "Co-pilot: " << car.get_co_pilot() << std::endl;
    }
}

// setters for Racer
void Racer::set_name(std::string name)
{
    m_name = name;
}

void Racer::set_sex(std::string sex)
{
    m_sex = sex;
}

void Racer::set_birthdate(Date birthdate)
{
    m_birthdate = birthdate;
}

void Racer::set_team(std::string team)
{
    m_team = team;
}

void Racer::add_Car(Car& car)
{
    m_cars.push_back(car);
}

// destructor for Racer
Racer::~Racer()
{
    std::cout << "Destructor called for a Racer object" << std::endl;
}

// constructors for Car
Car::Car()
{
    std::cout << "Default constructor called for a Car object" << std::endl;
}

Car::Car(std::string brand, std::string pilot, std::string co_pilot) :
m_brand{brand}, m_pilot{pilot}, m_co_pilot{co_pilot}
{
    std::cout << "Custom constructor called for a Car object" << std::endl;
}

// getters for Car
std::string Car::get_brand() const
{
    return m_brand;
}

std::string Car::get_pilot() const
{
    return m_pilot;
}

std::string Car::get_co_pilot() const
{
    if (m_co_pilot.has_value())
    {
        return m_co_pilot.value();
    }
    else
    {
        return "There is no co-pilot";
    }
}

// setters for Car object
void Car::set_brand(std::string brand)
{
    m_brand = brand;
}

void Car::set_pilot(std::string pilot)
{
    m_pilot = pilot;
}

void Car::set_co_pilot(std::string co_pilot)
{
    m_co_pilot = co_pilot;
}

// destructor for Car object
Car::~Car()
{
    std::cout << "The destructor was called for a Car object" << std::endl;
}