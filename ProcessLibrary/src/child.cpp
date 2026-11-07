#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Child process is running!" << std::endl;
    std::cout << "Received arguments:" << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }

    std::cout << "Press Enter to finish..." << std::endl;

    std::cin.get();

    return 42;
}