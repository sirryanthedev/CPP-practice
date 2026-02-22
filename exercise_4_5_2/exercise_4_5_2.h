#ifndef exercise_4_5_2_h
#define exercise_4_5_2_h

const int MAX_SIZE{10};

class Stack
{   
    public:
        // default constructor
        Stack(int size = MAX_SIZE); // default value is 10
        // destructor
        ~Stack();
        // methods
        void print_stack() const;
        void init_stack();
        void push(char c);
        char pop();
        bool is_empty() const;
        bool is_full() const;
    private:
        char* m_elems; // pointer to the stack (stack on the heap)
        int m_top{};
        int m_capacity{};
};

#endif