#include <iostream>
#include "exercise_7_2_3.h"

int main()
{
    // create an instance of Article and test functionality
    Article article1{"tv", 500};
    article1.print_info();

    // create an instance of Game and test functionality
    Game cod{};
    // base class methods
    cod.set_price(99);
    cod.set_name("Call of duty");
    // Game (subclass) methods
    cod.set_type("cross-platform");
    cod.set_esrb(18);
    cod.print_info();

    // create an instance of Book and test functionality
    Book harrypotter{};
    harrypotter.set_name("Harry Potter and the Philosopher's Stone");
    harrypotter.set_price(49);
    harrypotter.set_author("J. K. Rowling");
    harrypotter.set_isbn("978-0-7475-3269-9");
    harrypotter.print_info();

    // create an instance of Comic and test functionality
    Comic watchmen{};
    // base class methods
    watchmen.set_name("Watchmen by Alan Moore; Dave Gibbons (Illustrator)");
    watchmen.set_price(39);
    watchmen.set_author("Alan Moore & Dave Gibbons");
    watchmen.set_isbn("9781401245252");
    // Comic (subclass) methods
    watchmen.set_serial_name("Watchmen (often referred to in catalogs as Watchmen Vol. 1 or simply the Watchmen limited series)");
    watchmen.set_serial_number(12);
    watchmen.print_info();

    // test added functionality for exercise 7_2_3
    std::cout << std::endl << "------ test added functionality for exercise 7_2_3 ------" << std::endl;
    
    // create an instance of Game and test its functionality
    Game fortnite("Fortnite", 0);
    fortnite.set_type("cross-platform");
    fortnite.set_esrb(13);
    fortnite.print_info();

    // create an instance of Book and test its functionality
    Book richdadpoordad("Rich Dad Poor Dad", 29);
    richdadpoordad.set_author("Robert T. Kiyosaki");
    richdadpoordad.set_isbn("9780446677455");
    richdadpoordad.print_info();

    // create an instance of Comic and test its functionality
    Comic onepiece("onepiece", 19);
    onepiece.set_author("Eichiro Oda");
    onepiece.set_isbn("978-1569319017");
    onepiece.set_serial_name("One Piece");
    onepiece.print_info();
    
    return 0;
}