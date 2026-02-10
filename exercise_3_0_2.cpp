#include <iostream>

int main()
{
    const int amount{3}; // 3 numbers
    float array[amount]{}; // create null-initialised array with room for 3 lengths

    for (int i = 0; i < amount; i++)
    {
        std::cout << "Enter length n" << i + 1 << " in centimeters" << ": ";
        std::cin >> array[i];
        array[i] /= 2.54;
        std::cout << "Length n" << i + 1 << " is " << array[i] << " inch.\n";
    }

    return 0;
}
