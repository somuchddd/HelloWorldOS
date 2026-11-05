#include "../include/process.h"
#include <iostream>

int main()
{
    Process process;

    std::cout << "Starting process..." << std::endl;

#ifdef _WIN32
    if (!process.start("child.exe"))
#else
    if (!process.start("./child"))
#endif

    {
        std::cout << "Failed to start process!" << std::endl;
        return 1;
    }

    std::cout << "Process started!"<< std::endl;

    int exitCode = -1;

    if (!process.wait(exitCode))
    {
        std::cout << "Failed to wait for process!" << std::endl;
        return 1;
    }

    std::cout << "Process finished!" << std::endl;
    std::cout << "Exit code: " << exitCode << std::endl;

    return 0;
}