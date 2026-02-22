#include "exercise_5_2_3.h"
#include <iostream>

static void check_parentheses(const std::string sentence);

int main()
{
    std::cout << "Let's create stack 1" << std::endl;
    Stack my_stack;
    my_stack.init_stack();
    my_stack.push('h');
    my_stack.push('e');
    my_stack.push('l');
    my_stack.push('l');
    my_stack.push('o');
    my_stack.print_stack();
    std::cout << std::endl;

    std::cout << "Let's create stack 2" << std::endl;
    Stack other_stack;
    other_stack.init_stack();
    other_stack.push('h');
    other_stack.push('i');
    other_stack.print_stack();
    std::cout << std::endl;

    std::cout << "Let's create stack 3 by initialising it using the first stack" << std::endl;
    Stack stack_3{my_stack};
    stack_3.print_stack();

    std::cout << std::endl << "Let's create the last stack by moving contents of stack 2 to this stack" << std::endl;
    Stack stack_4{std::move(other_stack)};
    std::cout << "Contents of stack 4: ";
    stack_4.print_stack();
    std::cout << '\n' << "Contents of stack 2 after the move: " << std::endl;
    other_stack.print_stack();

    return 0;
}

static void check_parentheses(const std::string sentence)
{
    Stack my_stack{2}; // constructor will make stacks of size 3, if no argument -> default value 10
    my_stack.init_stack();

    for (const auto c : sentence)
    {
        if (c == '(')
        {
            if (my_stack.is_full())
            {
                std::cerr << "The parentheses weren't closed correctly!\n";
                std::cerr << "The stack is full...\n";
                return;
            }
            my_stack.push('(');
        }

        else if (c == ')')
        {
            if (my_stack.is_empty())
            {
                std::cerr << "The parentheses weren't opened correctly!\n";
                return;
            }
            my_stack.pop();
        }
    }

    if (my_stack.is_empty())
    {
        std::cout << "The parentheses were closed correctly!\n";
    }
    else
    {
        std::cerr << "The parentheses weren't opened/closed correctly!\n";
        std::cerr << "The stack is empty...\n";
    }
}