#ifndef EXERCISE_7_3_2_H
#define EXERCISE_7_3_2_H

class Vector
{
    public:
        // destructor
        ~Vector();
        // methods
        void print_elements() const;
        void add_element(double element);
    private:
        int m_nelements{}; // number of elements
        double* m_elements{}; // pointer to elements
};

#endif