// FILE: scheduler.h
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
// Header file for the main scheduler file

#include <iostream>
#include <string>
#include <queue>
#include "process.h"
using namespace std;


// Takes in different commands and sets global variables to it
int commandDecider (int argc, char **argv);

// readfile
// Reads the input file and builds the initial process queue
bool readFile(const string &filename, const string &type, bool preemptive, queue<Process> &ready);

// compareByArrival
// Comparator function to sort processes by arrival time
bool compareByArrival(const Process& a, const Process& b);

//initialize Globals
string type = "FCFS";
bool preemptive = false;
int quanta = 10;
string file = "";
bool verbose = false;