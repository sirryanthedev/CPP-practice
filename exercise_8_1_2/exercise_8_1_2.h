#ifndef EXERCISE_8_1_2_H
#define EXERCISE_8_1_2_H

#include <string>
#include <vector>

class Article
{
    public:
        // constructors
        Article();
        Article(const std::string& name,const int& price);

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
        void add_article(Article* article);
    private:
        std::vector<Article*> m_articles{};
};

#endif