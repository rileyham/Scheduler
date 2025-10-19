// scheduler.h
// Header file for the main scheduler file

using namespace std;
#include <iostream>
#include <string>
#include <queue>
#include "process.h"

// Takes in different commands and sets global variables to it
int commandDecider (int argc, char **argv);

// readfile
// Reads the input file and builds the initial process queue
queue<Process> readFile(const string &filename, const string &type, bool preemptive);

// compareByArrival
// Comparator function to sort processes by arrival time
bool compareByArrival(const Process& a, const Process& b);

//itialize Globals
string type = "FCFS";
bool preemptive = false;
int quanta = 10;
string file = "";
bool verbose = false;