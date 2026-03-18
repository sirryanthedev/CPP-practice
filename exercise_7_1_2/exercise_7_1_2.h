#ifndef EXERCISE_7_1_2_H
#define EXERCISE_7_1_2_H

#include <string>

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
        void print_info() const;

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
    void set_type(std::string& type);
    void set_esrb(int& esrb);
private:
    std::string m_type{}; // e.g. pc, ps4, xbox one, etc.
    int m_esrb{};
};

class Book : public Article
{
public:
    // getters
    std::string get_author() const;
    int get_isbn() const;
    void print_info() const;

    // setters
    void set_author(const std::string& author);
    void set_isbn(const int& isbn);
private:
    std::string m_author{};
    int m_isbn{};
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
#endif // EXERCISE_7_1_2_H