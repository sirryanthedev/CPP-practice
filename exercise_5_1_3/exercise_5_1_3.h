#ifndef EXERCISE_5_1_3_H
#define EXERCISE_5_1_3_H

class coordinate
{
    public:
        coordinate(); // default constructor
        coordinate(int a, int b); // custom constructor
        // getters
        int get_x() const;
        int get_y() const;
        // setters
        void set_x(int a);
        void set_y(int b);
        // output x and y
        void show_coordinate() const;
        // euclidic distance
        double distance_to(coordinate&& other) const; // && -> accept rvalue as parameter
    private:
        int m_x{};
        int m_y{};
};

#endif