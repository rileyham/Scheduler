// FILE: process.h
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
//
//  Interface of the process class.
//
#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    Process(int ID, int Arrival_Time, int Total_CPU_Burst, int Priority);
    int getId() const;
    int getArrivalTime() const;
    int getTotalCpuBurst() const;
    int getPriority() const;
    int getRemainingCpuBurst() const;
    void decrementRemainingCpuBurst(int burst) { remainingCPUBurst -= burst; }

private:
    int id;
    int arrivalTime;
    int totalCpuBurst;
    int remainingCPUBurst;
    int priority;
};

#endif
