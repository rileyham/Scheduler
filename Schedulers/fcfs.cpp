// FILE: fcfs.cpp
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
#include "fcfs.h"
#include <iostream>
#include <string>
using namespace std;


void FCFS(queue<Process> ready, bool verbose, string &response ) {
    if (ready.empty()) {
        if (verbose) response = "[FCFS] No processes to schedule.\n";
        response = "The average wait time is 0.0";
        return;
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
            if (verbose) response +=  "[FCFS] CPU idle until t=" + to_string(arrival) + "\n";
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
            response += "P_" + to_string(p.getId()) +
                "  arrive=" + to_string(arrival) +
                "  start="  + to_string(start) +
                "  finish=" + to_string(finish) +
                "  wait="   + to_string(wait) + "\n";
        }

    }
    const double avg_wait =
        static_cast<double>(total_wait) / static_cast<double>(count);

    if (verbose) response += "[FCFS] Average waiting time = " + to_string(avg_wait) + "\n";
    response += "The average wait time is " + to_string(avg_wait);
    return;

}
