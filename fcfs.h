#ifndef FCFS_H
#define FCFS_H

#include <queue>
#include <process.h>

class FCFS {
public:
    FCFS(bool verbose = false);
    double schedule(std::queue<Process> ready);

private:
    bool verbose;
};

#endif// FCFS_H
