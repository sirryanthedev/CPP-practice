#include "exercise_5_4_4.h"
#include <iostream>

int main()
{
    std::cout << "Creating birthdate1" << std::endl;
    Date birthdate1{};
    birthdate1.set_day(15);
    birthdate1.set_month(12);
    birthdate1.set_year(1999);

    std::cout << "Creating birthdate2" << std::endl;
    Date birthdate2{};
    birthdate2.set_day(1);
    birthdate2.set_month(5);
    birthdate2.set_year(2002);

    std::cout << "Creating car1" << std::endl;
    Car car1{"Lamborghini", "Jeremy", "Joe"};

    std::cout << "Creating car2" << std::endl;
    Car car2{};
    car2.set_brand("Bmw");
    car2.set_pilot("Frank");

    std::cout << "Creating racer1" << std::endl;
    Racer racer1{"Max", "Male", birthdate1, "Ferrari"};
    racer1.add_Car(car1);
    racer1.add_Car(car2);
    
    std::cout << "Viewing all cars of racer1" << std::endl;
    racer1.view_Cars();

    std::cout << "Creating racer2" << std::endl;
    Racer racer2{};
    racer2.set_birthdate(birthdate2);
    racer2.set_name("Lily");
    racer2.set_sex("Female");
    racer2.set_team("Bugatti");

    std::cout << "Getting info of racer2 using built in methods" << std::endl;
    racer2.get_birthdate(); // direct output to the terminal
    std::cout << "name: " << racer2.get_name() << std::endl
    << "sex: " << racer2.get_sex() << std::endl
    << "team: " << racer2.get_team() << std::endl;

    std::cout << "The end" << std::endl;

    return 0;
}