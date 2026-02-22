#ifndef exercise_5_2_3_h
#define exercise_5_2_3_h

const int MAX_SIZE{10};

class Stack
{   
    public:
        // default constructor
        Stack(int size = MAX_SIZE); // default value is 10
        // destructor
        ~Stack();
        // copy constructor
        Stack(const Stack& other);
        // move constructor
        Stack(Stack&& other);
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