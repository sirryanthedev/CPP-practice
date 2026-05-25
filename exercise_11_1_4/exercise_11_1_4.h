#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>

class Article
{
    public:
        // constructors
        Article();
        Article(const std::string& name,const int& price);
        virtual ~Article() = default;

        // copy
        Article(const Article& other);

        // move
        Article(Article&& other) noexcept;

        // getters
        std::string get_name() const;
        int get_price() const;
        virtual void print_info() const;

        // setters
        void set_name(const std::string& name);
        void set_price(const int& price);
    private:
        std::string m_name{};
        int m_price{};
};

class Game : public Article
{
public:
    // constructor
    Game(const std::string& name, const int& price, const std::string& type, const int& esrb);
    // getters
    std::string get_type() const;
    int get_esrb() const;
    void print_info() const;

    // setters
    void set_type(const std::string& type);
    void set_esrb(int esrb);
private:
    std::string m_type{}; // e.g. pc, ps4, xbox one, etc.
    int m_esrb{};
};

class Book : public Article
{
public:
    // constructor
    Book(const std::string& name, const int& price, const std::string& author, const std::string& isbn);
    // getters
    std::string get_author() const;
    std::string get_isbn() const;
    void print_info() const;

    // setters
    void set_author(const std::string& author);
    void set_isbn(const std::string& isbn);
private:
    std::string m_author{};
    std::string m_isbn{};
};

class Comic : public Book
{
public:
    // constructor
    Comic(const std::string& name, const int& price, const std::string& author, const std::string& isbn, const std::string& serial_name, const int& serial_number);

    // getters
    std::string get_serial_name() const;
    int get_serial_number() const;
    void print_info() const;

    // setters
    void set_serial_name(const std::string& serial_name);
    void set_serial_number(const int& serial_number);

private:
    std::string m_serial_name{};
    int m_serial_number{};
};

class Shop
{
    public:
        void show_articles() const;
        void add_article(std::unique_ptr<Article> article);
        void remove_article(const std::string& name);
        void show_stock() const;
    protected:
        std::vector<std::unique_ptr<Article>> m_articles{};
        std::map<std::string, int> m_stock{};
};

class Shoppingcart : public Shop
{
    public:
        void add_to_cart(const std::string& name);
        void display_cart() const;
        float show_price() const;
    private:
        std::vector<std::unique_ptr<Article>> m_cart{};
};