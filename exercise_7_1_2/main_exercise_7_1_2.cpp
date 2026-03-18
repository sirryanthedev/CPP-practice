#include <iostream>
#include "exercise_7_1_2.h"

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
    cod.set_esrb("Mature 17+");
    cod.print_info();

    // create an instance of Book and test functionality
    Book harrypotter{};
    harrypotter.set_author("J. K. Rowling");
    harrypotter.set_isbn(9780747532743);
    harrypotter.print_info();

    // create an instance of Comic and test functionality
    Comic watchmen{};
    // base class methods
    watchmen.set_author("Alan Moore & Dave Gibbons");
    watchmen.set_isbn(9781401245252);
    // Comic (subclass) methods
    watchmen.set_serial_name("Watchmen (often referred to in catalogs as Watchmen Vol. 1 or simply the Watchmen limited series)");
    watchmen.set_serial_number(12);
    watchmen.print_info();

    return 0;
}