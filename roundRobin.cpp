// FILE: roundRobin.cpp
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025

#include "roundRobin.h"
#include <vector>
#include <iostream>
using namespace std;

void RoundRobin(std::queue<Process> processes, int timeQuantum, bool isVerbose, string& response) {
    queue<Process> readyQueue;
    int elapsedTime = 0;
    int numProcesses = processes.size();
    bool processCompleted = false;

    // Initially load processes that have already arrived
    for (int i = 0; i < numProcesses; ++i) {
        if (processes.front().getArrivalTime() <= elapsedTime) {
            readyQueue.push(processes.front());
            processes.pop();
        }
    }

    while (!readyQueue.empty() || !processes.empty()) {

        // if readyQueue is empty, we need to advance time
        if (readyQueue.empty()) {
            cout << "CPU is idle at time " << elapsedTime << endl;
            elapsedTime++;
            // Load any new processes that have arrived
            while (!processes.empty() && processes.front().getArrivalTime() <= elapsedTime) {
                readyQueue.push(processes.front());
                processes.pop();
            }
        }

        else {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();
            if (currentProcess.getArrivalTime() <= elapsedTime) {
                if(currentProcess.getRemainingCpuBurst() <= timeQuantum) {
                    // Process finishes execution this quantum
                    elapsedTime += currentProcess.getRemainingCpuBurst();
                    int waitTime = elapsedTime - currentProcess.getArrivalTime() - currentProcess.getTotalCpuBurst();

                    //cout << "Process " << currentProcess.getId() << " finished at time " << elapsedTime << " ";
                    cout << "Process " << currentProcess.getId() << " had a wait time of " << waitTime << endl;

                    if (isVerbose) {
                        response += "P" + to_string(currentProcess.getId()) + " finished at time " + to_string(elapsedTime) + " ";
                        response += " Wait Time: " + to_string(waitTime) + "\n";
                    }
                    else {
                        response += "P" + to_string(currentProcess.getId()) + " Wait Time: " + to_string(waitTime) + "\n";
                    }
                    // Process is done, do not requeue
                    processCompleted = true;

                } else {
                    // Process does not finish, requeue it
                    elapsedTime += timeQuantum;
                    cout << "Process " << currentProcess.getId() << " ran for " << timeQuantum << " units." << endl;
                    currentProcess.decrementRemainingCpuBurst(timeQuantum);
                }
            }

            for (int i = 0; i < processes.size(); ++i) {
                if (processes.front().getArrivalTime() <= elapsedTime) {
                    readyQueue.push(processes.front());
                    processes.pop();
                }
            }
            if (!processCompleted) {
                readyQueue.push(currentProcess);
            }
            processCompleted = false;
        }
    }
    //cout << "Elapsed Time: " << elapsedTime << endl;

    if (isVerbose) {
        response += "Elapsed Time: " + to_string(elapsedTime) + "\n";
    }
    return;
}