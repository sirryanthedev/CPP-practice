#ifndef EXERCISE_5_4_3_H
#define EXERCISE_5_4_3_H

#include "exercise_4_3_2.h" // for date class
#include <string>
#include <optional>
#include <vector>

enum class Relationship
{
    single, 
    engaged, 
    married, 
    divorced
};

class Contact
{
    public:
        Contact(); // default constructor
        Contact(std::string name, 
                std::vector<std::string> email, 
                Date birthdate, 
                std::optional<std::string> nickname,
                Relationship status); // custom constructor
        // getters
        void output_name() const; 
        void output_email() const;
        void output_birthdate() const;
        void output_nickname() const;
        void output_status() const;
        // setters
        void set_name(std::string name);
        void set_email(std::string email);
        void set_birthdate(Date birthdate);
        void set_nickname(std::string nickname);
        void set_status(Relationship status);
    private:
        std::string m_name{};
        std::vector<std::string> m_email{};
        Date m_birthdate{};
        std::optional<std::string> m_nickname{};
        Relationship m_status{};
};

class AddressBook
{   
    public:
        // getter
        void output_contacts() const;
        // setter
        void add_contact(Contact contact);
    private:
        std::vector<Contact> m_contacts{};
};

#endif