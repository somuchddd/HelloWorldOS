#include "process.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
#endif

bool Process::start(const std::string& program)
{
    #ifdef _WIN32
    STARTUPINFOA startup{};
    startup.cb = sizeof(startup);
    
    std::string command = program;
    
    return CreateProcessA(
        nullptr,
        command.data(),
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        nullptr,
        &startup,
        &info
    );

    #else
    pid = fork();

    if (pid == 0){
        execlp(program.c_str(), program.c_str(), (char*)nullptr);
        _exit(127);
    }

    return pid > 0;

    #endif
}

bool Process::wait(int& exitCode)
{
    #ifdef _WIN32

    if (WaitForSingleObject(info.hProcess, INFINITE) != WAIT_OBJECT_0){
        return false;
    }

    DWORD code;

    if(!GetExitCodeProcess(info.hProcess, &code)){
        return false;
    }

    exitCode = static_cast<int>(code);

    CloseHandle(info.hProcess);
    CloseHandle(info.hThread);

    return true;

    #else
    
    int status;
    if (waitpid(pid, &status, 0) == -1){
        return false;
    }

    if (WIFEXITED(status)){
        exitCode = WEXITSTATUS(status);
    }

    else{
        exitCode = -1;
    }

    return true;

    #endif
}