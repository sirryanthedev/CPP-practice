#include <iostream>

int main()
{
    class example1
    {
        public:
            virtual void hello()
            {
               std::cout << "hello!" << std::endl; 
            }
    };
    
    class example2
    {
        public:
            /*virtual*/ void hello()
            {
               std::cout << "hello!" << std::endl; 
            }
    };
    
    // size of class example 1 (8)
    std::cout << "size of class example 1 (virtual method): " << sizeof(example1) << std::endl;

    // size of the identical class example 2 without virtual method (1)
    std::cout << "size of class example 2 (no virtual method): " << sizeof(example2) << std::endl;

    return 0;
}