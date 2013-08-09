
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <istream>
#include <list>

void addProcess(std::string const & cmd, std::list<pid_t> & process)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return;
    if (pid == 0)
    {
        system(cmd.c_str());
        exit(0);
    }
    process.push_back(pid);
}

bool waitProcess(std::list<pid_t> & process)
{
    int status = 0;
    pid_t pid = wait(&status);
    if (pid == -1)
        return (false);
    process.remove(pid);
    return (true);
}

int main(int argc, char *argv[])
{
    std::fstream        file;
    std::string         cmd;
    unsigned int        nProcess;
    std::list<pid_t>    process;
    std::istream    *   stream;

    if (argc != 3)
    {
        std::cerr << "Usage : " << argv[0] << " <cmd file> <threads>" << std::endl;
        return (1);
    }
    if (std::string(argv[1]) != "-")
    {
        file.open(argv[1]);
        if (!file)
        {
            std::cerr << "Error : Can't open file" << std::endl;
            return (1);
        }
        stream = &file;
    }
    else
        stream = &std::cin;
    nProcess = atoi(argv[2]);
    if (nProcess <= 0)
    {
        std::cerr << "Error : threads argument must be > 0" << std::endl;
        return (1);
    }
    while (getline(*stream, cmd))
    {
        if (process.size() >= nProcess)
            while (waitProcess(process) == false && process.size() > 0)
                ;
        addProcess(cmd, process);
    }
    while (process.size())
    {
        waitProcess(process);
    }
    return (0);
}

