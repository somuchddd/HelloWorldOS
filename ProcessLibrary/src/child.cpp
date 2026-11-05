#include <iostream>

int main()
{
    std::cout << "Child process is running!" << std::endl;
    std::cout << "Press Enter to finish..." << std::endl;

    std::cin.get();

    return 42;
}