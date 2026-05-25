#include <iostream>
#include <stdbool.h>
#include <algorithm>
#include "exercise_11_1_4.h"

// Article class

// constructors
Article::Article() // default constructor
{
    std::cout << "Default constructor called for instance of Article" << std::endl;
}

Article::Article(const std::string& name,const int& price) : m_name{name}, m_price{price} // custom constructor
{
    std::cout << "Custom constructor called for instance of Article" << std::endl;
}

Article::Article(const Article& other) : m_name{other.m_name}, m_price{other.m_price}
{
    std::cout << "Copy constructor called for instance of Article" << std::endl;
}

Article::Article(Article&& other) noexcept : m_name{std::move(other.m_name)}, m_price{other.m_price}
{
    other.m_price = 0;
    std::cout << "Move constructor called for instance of Article" << std::endl;
}

// getters
std::string Article::get_name() const
{
    return m_name;
}

int Article::get_price() const
{
    return m_price;
}

void Article::print_info() const
{
    std::cout << "article name: " << m_name << std::endl
    << "article price: " << m_price << std::endl;
}

// setters
void Article::set_name(const std::string& name)
{
    m_name = name;
}

void Article::set_price(const int& price)
{
    m_price = price;
}

// Game class

// constructor

Game::Game(const std::string& name, const int& price, const std::string& type, const int& esrb) : Article(name, price)
{
    m_type = type;
    m_esrb = esrb;
}

// getters

std::string Game::get_type() const
{
    return m_type;
}

int Game::get_esrb() const
{
    return m_esrb;
}

void Game::print_info() const
{
    Article::print_info();
    std::cout << "game type: " << m_type << std::endl
    << "esrb: " << m_esrb << std::endl;
}

// setters

void Game::set_type(const std::string& type)
{
    m_type = type;
}

void Game::set_esrb(int esrb)
{
    m_esrb = esrb;
}

// Book class

// constructor

Book::Book(const std::string& name, const int& price, const std::string& author, const std::string& isbn) : Article(name, price)
{
    m_author = author;
    m_isbn = isbn;
}

// getters

std::string Book::get_author() const
{
    return m_author;
}

std::string Book::get_isbn() const
{
return m_isbn;
}

void Book::print_info() const
{
    Article::print_info();
    std::cout << "author: " << m_author << std::endl
    << "isbn: " << m_isbn << std::endl;
}

void Book::set_author(const std::string& author)
{
    m_author = author;
}

void Book::set_isbn(const std::string& isbn)
{
    m_isbn = isbn;
}

// Comic class

// constructor

Comic::Comic(const std::string& name, const int& price, const std::string& author, const std::string& isbn, const std::string& serial_name, const int& serial_number) : Book(name, price, author, isbn)
{
    m_serial_name = serial_name;
    m_serial_number = serial_number;
}

// getters

std::string Comic::get_serial_name() const
{
    return m_serial_name;
}

int Comic::get_serial_number() const
{
    return m_serial_number;
}

void Comic::print_info() const
{
    Book::print_info();
    std::cout << "serial name: " << m_serial_name << std::endl
    << "serial number: " << m_serial_number << std::endl;
}

// setters

void Comic::set_serial_name(const std::string& serial_name)
{
    m_serial_name = serial_name;
}

void Comic::set_serial_number(const int& serial_number)
{
    m_serial_number = serial_number;
}

// Shop class

// getter
void Shop::show_stock() const
{
    std::cout << "\n=============-----=============\n"
    << "Stock:\n";
    for (const auto& item : m_stock)
    {
        std::cout << "* " << item.first << " : " << item.second << "x available" << std::endl;
    }
}

void Shop::show_articles() const
{
    for (const auto& item : m_articles)
    {
       item->print_info();
       std::cout << std::endl; 
    }
}

// setter

void Shop::add_article(std::unique_ptr<Article> article)
{
    std::string article_name{article->get_name()};
    m_articles.push_back(std::move(article));
    
    // update stock
    auto item = m_stock.find(article_name);

    // item not found
    if (item == m_stock.end())
    {
        m_stock[article_name] = 1;
        return;
    }

    // item found
    m_stock[article_name] += 1;
}

void Shop::remove_article(const std::string& name)
{
    bool found = false;
    size_t idx{};
    for (const auto& item : m_articles)
    {
        // article found in m_articles
        if (item->get_name() == name)
        {
            // the item is in stock
            if (m_stock[name] > 0)
            { 
            m_stock[name] -= 1;
            }

            // the item is not in stock - error
            else
            {
                std::cerr << "The item is not in stock, therefore it can't be removed!" << std::endl;
                return;
            }

            m_articles.erase(m_articles.begin() + idx);
            found = true;

            std::cout << "The item "<< name << "was found and erased from the shop" << std::endl;
            break;
        }
        idx++;
    }
    if (!found)
    {
        std::cout << "The item " << name << "was not found and thus couldn't be erased" << std::endl;
    }
}

// Shoppingcart class 

void Shoppingcart::add_to_cart(const std::string& name)
{
    bool found = false;

    for (size_t i{}; i < m_articles.size(); ++i)
    {
        if (m_articles[i]->get_name() == name)
        {
            found = true;

            // check whether m_articles[i] is a game - ESRB check
            if (Game* game = dynamic_cast<Game*>(m_articles[i].get()))
            {
                int age{};

                std::cout << "What's your age: " << std::endl;
                std::cin >> age;

                if (age < game->get_esrb())
                {
                    std::cout << "You are too young to get this game!" << std::endl;
                    return;
                }
            }

            // update stock
            if (m_stock[name] > 0)
            {
                m_stock[name] -= 1;
            }

            else
            {
                std::cerr << "Items which aren't in stock can't be added to cart" << std::endl;
                return;
            }

            // move ownership to cart
            m_cart.push_back(std::move(m_articles[i]));

            // remove empty slot
            m_articles.erase(m_articles.begin() + i);

            std::cout << name << "was added to your cart succesfully" << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "The article \"" << name
                  << "\" is not available"
                  << std::endl;
    }
}

void Shoppingcart::display_cart() const
{
    if (m_cart.size() < 1)
    {
        std::cout << "Your cart is empty..." << std::endl;
    }

    else
    {
        std::cout << "Cart Contents: " << std::endl;
        for (const auto& item : m_cart)
            {
                std::cout << item->get_name() << std::endl;
            }
    }
}

float Shoppingcart::show_price() const
{
    float price{};
    for (const auto& item : m_cart)
    {
        price += item->get_price();
    }
    std::cout << "The total price of all the items in your cart is " << "$" << price << "." << std::endl;
    return price;
}