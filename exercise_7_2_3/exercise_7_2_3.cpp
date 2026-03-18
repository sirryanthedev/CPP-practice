#include <iostream>
#include "exercise_7_2_3.h"

// Article class

// constructors

Article::Article() // default constructor
{
    std::cout << "Default constructor called for instance of Article" << std::endl;
}

Article::Article(const std::string& name,const int& price) : m_name{name}, m_price{price} // converting constructor
{
    std::cout << "Converting constructor called for instance of Article" << std::endl;
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

// constructor to initialise base class (Article)

Game::Game(const std::string& name, int price) : Article{name, price}
{
    std::cout << "Constructor called for instance of Game to initialise base class (Article)" << std::endl;
}

// default constructor

Game::Game() : m_type{}, m_esrb{}
{
    std::cout << "Default constructor called for instance of Game" << std::endl;
}

// destructor

Game::~Game()
{
    std::cout << "Destructor called for instance of Game" << std::endl;
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

// constructor to initialise base class (Article)

Book::Book(const std::string& name, int price) : Article{name, price}
{
    std::cout << "Constructor called for instance of Book to initialise base class (Article)" << std::endl;
}

// default constructor

Book::Book() : m_author{}, m_isbn{}
{
    std::cout << "Default constructor called for instance of Book" << std::endl;
}

// converting constructor

Book::Book(const std::string& author, const std::string& isbn) : m_author{author}, m_isbn{isbn}
{
    std::cout << "Converting constructor called for instance of Book" << std::endl;
}

// destructor

Book::~Book()
{
    std::cout << "Destructor called for instance of Book" << std::endl;
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

// constructor to initialise base class (Article)

Comic::Comic(const std::string& name, int price) : Book(name, price)
{
    std::cout << "Constructor called for instance of Comic to initialise base class (Article)" << std::endl;
}

// default constructor

Comic::Comic() : m_serial_name{}, m_serial_number{}
{
    std::cout << "Default constructor called for instance of Comic" << std::endl;
}

// converting constructor
Comic::Comic(const std::string& serial_name, int serial_number) : m_serial_name{serial_name}, m_serial_number{serial_number}
{
    std::cout << "Converting constructor called for instance of Comic" << std::endl; 
}

// destructor
Comic::~Comic()
{
    std::cout << "Destructor called for instance of Comic" << std::endl;
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