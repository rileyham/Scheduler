// scheduler.h
// Header file for the main scheduler file

using namespace std;
#include <iostream>
#include <string>

// Takes in different commands and sets global variables to it
int commandDecider (int argc, char **argv);

//itialize Globals
string type = "FCFS";
bool preemptive = false;
int quanta = 10;
string file = "";
bool verbose = false;