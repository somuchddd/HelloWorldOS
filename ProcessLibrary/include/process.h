#ifndef PROCESS_H
#define PROCESS_H

#include <string>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/types.h>
#endif

class Process
{
    private:
    #ifdef _WIN32
        PROCESS_INFORMATION info{};

    #else
        pid_t pid = -1;
        
    #endif

    public:
        bool start(const std::string& program);
        bool wait(int& exitCode);
};

#endif