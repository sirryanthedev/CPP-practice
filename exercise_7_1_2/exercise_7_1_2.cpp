#include <iostream>
#include "exercise_7_1_2.h"

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