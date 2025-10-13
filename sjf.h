// FILE: priority.h
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
//
//  Interface of the shortest job first scheduling algorithm.
//
#ifndef SJF_H
#define SJF_H

#include <string>
#include "process.h"
#include <queue>
using namespace std;

void SJFNonPreemptive(std::queue<Process> processes, bool isVerbose, string& response);
void SJFPreemptive(std::queue<Process> processes, bool isVerbose, string& response);

#endif