#ifndef exercise_4_3_2_h
#define exercise_4_3_2_h

class Date
{
    public:
        // constructors
        Date(); // default-constructor
        Date(int day, int month, int year); // values for all memers entered
        // getters
        int get_day() const;
        int get_month() const;
        int get_year() const;
        // setters
        void set_day(int day);
        void set_month(int month);
        void set_year(int year); 
        // method to output the full date yyyy/mm/dd
        void print_full_date() const;
    private:
        // private null-initialised member variables
        int m_day{};
        int m_month{};
        int m_year{};
};

#endif