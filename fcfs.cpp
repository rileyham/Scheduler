// FILE: fcfs.cpp
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
#include "fcfs.h"
#include <iostream>

double FCFS::schedule(std::queue<Process> ready) {
    if (ready.empty()) {
        if (verbose) std::cout << "[FCFS] No processes to schedule.\n";
        return 0.0;
    }

    int time = 0; // current CPU time
    long total_wait = 0;// sum of per-process wait times
    int count = 0; // number of processes seen

    while (!ready.empty()) {
        Process p = ready.front();
        ready.pop();

        const int arrival = p.getArrivalTime();
        const int burst   = p.getTotalCpuBurst();

        // if the CPU is idle until this process arrives, advance the time
        if (time < arrival) {
            if (verbose) std::cout << "[FCFS] CPU idle until t=" << arrival << "\n";
            time = arrival;
        }

        const int start = time;
        const int wait = start - arrival;
        const int finish = start + burst;

        // run the process to completion
        time = finish;
        total_wait += static_cast<long long>(wait);
        ++count;

        if (verbose) {
            std::cout << "P_" << p.getId()
                    << "  arrive=" << arrival
                    << "  start="  << start
                    << "  finish=" << finish
                    << "  wait="   << wait
                    << "\n";
        }
    }
    const double avg_wait =
        static_cast<double>(total_wait) / static_cast<double>(count);

    if (verbose) std::cout << "[FCFS] Average waiting time = " << avg_wait << "\n";
    return avg_wait;
}
