#include "exercise_5_4_3.h"
#include <iostream>

// constructors
Contact::Contact() : m_status{Relationship::single}
{
    std::cout << "Default constructor called" << std::endl;
}

Contact::Contact(std::string name, 
                std::vector<std::string> email, 
                Date birthdate, 
                std::optional<std::string> nickname,
                Relationship status) : m_name{name}, m_email{email}, m_birthdate{birthdate}, m_nickname{nickname}, m_status{status}
{
    std::cout << "Custom constructor called" << std::endl;
}

// getters
void Contact::output_name() const
{
    std::cout << m_name << std::endl;
}

void Contact::output_email() const
{
    for (const std::string& email : m_email)
    {
        std::cout << email << std::endl;
    }
}

void Contact::output_birthdate() const
{
    std::cout << m_birthdate.get_year() << '/' << m_birthdate.get_month() << '/' << m_birthdate.get_day() << std::endl; // yyyy/mm/dd
}

void Contact::output_nickname() const
{
    if (m_nickname.has_value())
    {
        std::cout << m_nickname.value() << std::endl;
    }
    else
    {
        std::cout << "There is no nickname" << std::endl;
    }
}

void Contact::output_status() const
{
    switch (m_status)
    {
        case Relationship::single:
            std::cout << "Single" << std::endl;
            break;
        case Relationship::engaged:
            std::cout << "Engaged" << std::endl;
            break;
        case Relationship::married:
            std::cout << "Married" << std::endl;
            break;
        case Relationship::divorced:
            std::cout << "Divorced" << std::endl;
            break;
        default:
            std::cout << "No status" << std::endl;
    }
}

// setters
void Contact::set_name(std::string name)
{
    m_name = name;
}

void Contact::set_email(std::string email)
{
    m_email.push_back(email);
}
void Contact::set_birthdate(Date birthdate)
{
    m_birthdate = birthdate;
}

void Contact::set_nickname(std::string nickname)
{
    m_nickname = nickname;
}

void Contact::set_status(Relationship status)
{
    m_status = status;
}

void AddressBook::output_contacts() const
{
    int number{};
    for (const Contact& contact : m_contacts)
    {
        std::cout << "INFO CONTACT N" << ++number << ":" << std::endl;
        std::cout << "name: ";
        contact.output_name();
        std::cout << "email: ";
        contact.output_email();
        std::cout << "birthdate: ";
        contact.output_birthdate();
        std::cout << "nickname: ";
        contact.output_nickname();
        std::cout << "status: ";
        contact.output_status();
        std::cout << std::endl;
        std::cout << "-----------------" << std::endl;
    }
}

void AddressBook::add_contact(Contact contact)
{
    m_contacts.push_back(contact);
}