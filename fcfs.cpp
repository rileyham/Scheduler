#include "fcfs.h"
#include <iostream>
using namespace std;

FCFS::FCFS(bool verbose_) : verbose(verbose_) {}

double FCFS::schedule(queue<Process> ready) {
    if (ready.empty()) {
        if (verbose) cout << "[FCFS] No processes to schedule.\n";
        return 0.0;
    }

    int time = 0;
    long long total_wait = 0;
    int count = 0; //count of processes

    while (!ready.empty()) {
        Process p = ready.front();
        ready.pop();

        //if the process isnt ready yet the CPU will wait
        if (time < p.arrival_time) {
            if (verbose) cout << "[FCFS] CPU idle until t=" << p.arrival_time << "\n";
            time = p.arrival_time;
        }

        //process will start now
        p.start_time = time;
        p.wait_time  = p.start_time - p.arrival_time;

        //current time plus how long it takes
        time = time + p.burst_time;
        p.finish_time = time;

        //increase the total waiting time and process count
        total_wait += p.wait_time;
        count++;

        if (verbose) {
            cout << p.id
                 << "  arrive=" << p.arrival_time
                 << "  start="  << p.start_time
                 << "  finish=" << p.finish_time
                 << "  wait="   << p.wait_time
                 << "\n";
        }
    }

    //average waiting time of all the processes
    double avg_wait = static_cast<double>(total_wait) / static_cast<double>(count);

    if (verbose) cout << "[FCFS] Average waiting time = " << avg_wait << "\n";
    return avg_wait;
}
