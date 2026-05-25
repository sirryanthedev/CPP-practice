#include <iostream>
#include <memory>
#include "exercise_11_1_4.h"

int main()
{
    // create and init instance of Game
    std::unique_ptr<Article> call_of_duty{std::make_unique<Game>("Call of duty", 99, "cross-platform", 18)};

    // create and init instance of Book
    std::unique_ptr<Article> harrypotter{std::make_unique<Book>("Harry Potter and the Philosopher's Stone", 49, "J. K. Rowling", "978-0-7475-3269-9")};

    // create and init instance of Comic 
    std::unique_ptr<Article> watchmen{std::make_unique<Comic>("Watchmen by Alan Moore; Dave Gibbons (Illustrator)", 39, "Alan Moore & Dave Gibbons", "9781401245252", "Watchmen (often referred to in catalogs as Watchmen Vol. 1 or simply the Watchmen limited series)", 12)};

    // create and init instance of Shoppingcart
    std::unique_ptr<Shoppingcart> cart{std::make_unique<Shoppingcart>()};

    // add articles to the Shop
    cart->add_article(std::move(call_of_duty));
    cart->add_article(std::move(harrypotter));
    cart->add_article(std::move(watchmen));

    std::cout << "Show articles in shop" << std::endl;
    cart->show_articles();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "add harrypotter book to the cart" << std::endl;
    cart->add_to_cart("Harry Potter and the Philosopher's Stone");
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "Output cart" << std::endl;
    cart->display_cart();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "add Call of duty to the cart" << std::endl;
    cart->add_to_cart("Call of duty");
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "output cart" << std::endl;
    cart->display_cart();
    
    std::cout << "--------------------" << std::endl;
    
    std::cout << "output total price of items in the cart" << std::endl;
    cart->show_price();
    
    std::cout << "--------------------" << std::endl;

    std::cout << "show remaining articles in stock" << std::endl;
    std::cout << std::endl << std::endl << "Items in stock:" << std::endl;
    cart->show_stock();

    std::cout << "DONE." << std::endl;
    return 0;
}