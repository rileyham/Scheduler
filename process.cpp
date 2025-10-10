// FILE: process.cpp
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
//
//  Implementation of the Process class.
//
#include "process.h"
Process::Process(int ID, int Arrival_Time, int Total_CPU_Burst, int Priority)
    : id(ID), arrivalTime(Arrival_Time), totalCpuBurst(Total_CPU_Burst), priority(Priority), remainingCPUBurst(Total_CPU_Burst) {}

int Process::getId() const {
    return id;
}

int Process::getArrivalTime() const {
    return arrivalTime;
}

int Process::getTotalCpuBurst() const {
    return totalCpuBurst;
}

int Process::getPriority() const {
    return priority;
}

int Process::getRemainingCpuBurst() const {
    return remainingCPUBurst;
}