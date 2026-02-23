#include <iostream>
#include "exercise_5_4_3.h"

int main()
{   
    Date birthdate{1, 1, 1999}; // parameters dd/mm/yyyy
    birthdate.print_full_date(); // output in yyyy/mm/dd
    Date another_birthdate(11, 10, 1987);

    // creating a contact
    Contact contact1;
    contact1.set_name("Joe");
    contact1.set_email("joe@gmail.com");
    contact1.set_status(Relationship::engaged);
    contact1.set_birthdate(birthdate);

    contact1.output_name();
    contact1.output_email();
    contact1.output_birthdate();
    contact1.output_status();
    contact1.output_nickname();

    std::cout << std::endl;

    // creating another contact
    Contact contact2;
    contact2.set_name("Murray");
    contact2.set_email("Murray@yahoo.org");
    contact2.set_status(Relationship::single);
    contact2.set_birthdate(another_birthdate);
    contact2.set_nickname("Murr");

    // create an addressbook
    AddressBook addressbook{};

    // add contacts to addressbook
    addressbook.add_contact(contact1);
    addressbook.add_contact(contact2);

    addressbook.output_contacts();

    return 0;
}