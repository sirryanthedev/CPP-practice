#ifndef exercise_4_2_2_h
#define exercise_4_2_2_h

class Date
{
    public:
        // getters
        int get_day() const;
        int get_month() const;
        int get_year() const;
        // setters
        void set_day(int day);
        void set_month(int month);
        void set_year(int year); 
    private:
        // private null-initialised member variables
        int m_day{};
        int m_month{};
        int m_year{};
};

#endif