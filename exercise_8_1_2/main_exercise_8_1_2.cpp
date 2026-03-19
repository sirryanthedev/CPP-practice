#include <iostream>
#include "exercise_8_1_2.h"

int main()
{
    // create an instance of Article
    Article article1{"tv", 500};

    // create an instance of Game
    Game cod{};
    // base class methods
    cod.set_price(99);
    cod.set_name("Call of duty");
    // Game (subclass) methods
    cod.set_type("cross-platform");
    cod.set_esrb(18);

    // create an instance of Book
    Book harrypotter{};
    harrypotter.set_name("Harry Potter and the Philosopher's Stone");
    harrypotter.set_price(49);
    harrypotter.set_author("J. K. Rowling");
    harrypotter.set_isbn("978-0-7475-3269-9");

    // create an instance of Comic 
    Comic watchmen{};
    // base class methods
    watchmen.set_name("Watchmen by Alan Moore; Dave Gibbons (Illustrator)");
    watchmen.set_price(39);
    watchmen.set_author("Alan Moore & Dave Gibbons");
    watchmen.set_isbn("9781401245252");
    // Comic (subclass) methods
    watchmen.set_serial_name("Watchmen (often referred to in catalogs as Watchmen Vol. 1 or simply the Watchmen limited series)");
    watchmen.set_serial_number(12);

    // create a shop and add articles
    Shop shop;
    shop.add_article(&article1);
    shop.add_article(&cod);
    shop.add_article(&harrypotter);
    shop.add_article(&watchmen);

    // test print method of Shop
    shop.show_articles();

    return 0;
}