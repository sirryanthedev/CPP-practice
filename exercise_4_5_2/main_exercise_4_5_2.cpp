#include "exercise_4_5_2.h"
#include <iostream>

static void check_parentheses(const std::string sentence);

int main()
{
    std::string sentence_1{"())()()"};
    std::string sentence_2{"(((4)-2*5)/2)+1))"};
    std::string sentence_3{"(5*(2+1)-8*(7-5))"};

    check_parentheses(sentence_1);
    check_parentheses(sentence_2);
    check_parentheses(sentence_3);
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