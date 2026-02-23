#ifndef EXERCISE_5_4_4_H
#define EXERCISE_5_4_4_H

#include "exercise_4_2_2.h" // for Date class
#include <string>
#include <optional>
#include <vector>

class Car
{
    public:
        // constructors
        Car();
        Car(std::string brand, std::string pilot, std::string co_pilot);
        // getters
        std::string get_brand() const;
        std::string get_pilot() const;
        std::string get_co_pilot() const;
        // setters
        void set_brand(std::string brand);
        void set_pilot(std::string pilot);
        void set_co_pilot(std::string co_pilot);
        // destructor
        ~Car();
    private:
        std::string m_brand{};
        std::string m_pilot{};
        std::optional<std::string> m_co_pilot{};
};

class Racer
{
    public:
        // constructors
        Racer();
        Racer(std::string name, std::string sex, Date birthdate, std::string team);
        // getters
        std::string get_name() const;
        std::string get_sex() const;
        void get_birthdate() const;
        std::string get_team() const;
        void view_Cars() const;
        // setters
        void set_name(std::string name);
        void set_sex(std::string sex);
        void set_birthdate(Date birthdate);
        void set_team(std::string team);
        void add_Car(Car& car);
        // destructor 
        ~Racer();
    private:
        std::string m_name{};
        std::string m_sex{};
        Date m_birthdate{};
        std::string m_team{};
        std::vector<Car> m_cars{};
};

#endif