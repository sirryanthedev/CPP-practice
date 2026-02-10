#ifndef exercise_4_4_2_h
#define exercise_4_4_2_h

const int MAX_SIZE{10};

class Stack
{   
    public:
        void print_stack() const;
        void init_stack();
        void push(char c);
        char pop();
        bool is_empty() const;
        bool is_full() const;
    private:
        char m_elems[MAX_SIZE]{}; // stack
        int m_top{};
};

#endif