// FILE: priority.h
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
//
//  Interface of the priority scheduling algorithm.
//
#ifndef PRIORITY_H
#define PRIORITY_H

#include <string>
#include "process.h"
#include <queue>
using namespace std;

void PriorityNonPreemptive(std::queue<Process> processes, bool isVerbose, string& response);
void PriorityPreemptive(std::queue<Process> processes, bool isVerbose, string& response);

#endif

