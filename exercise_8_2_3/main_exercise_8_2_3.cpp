#include <iostream>
#include "exercise_8_2_3.h"

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

    // create a Shoppingcart
    Shoppingcart cart;

    // add articles to the Shop
    cart.add_article(&article1);
    cart.add_article(&cod);
    cart.add_article(&harrypotter);
    cart.add_article(&harrypotter);
    cart.add_article(&watchmen);

    std::cout << "Show articles in shop" << std::endl;
    cart.show_articles();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "add harrypotter book to the cart" << std::endl;
    cart.add_to_cart(&harrypotter);
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "Output cart" << std::endl;
    cart.display_cart();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "add cod to the cart" << std::endl;
    cart.add_to_cart(&cod);
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "output cart" << std::endl;
    cart.display_cart();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "output total price of items in the cart" << std::endl;
    cart.show_price();
    
    std::cout << "--------------------" << std::endl;

    std::cout << "show remaining articles in Shop" << std::endl;
    std::cout << std::endl << std::endl << "REMAINING ARTICLES IN SHOP" << std::endl << std::endl;
    cart.show_articles();

    return 0;
}