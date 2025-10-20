// FILE: scheduler.cpp
// Group 1: Chase Gartner, Ryan Geisler, Riley Ham
// Operating Systems, Fall 2025
//
// Takes input in from user, decides which scheduler to use and sends the output
// Citation: Range Based Iteration https://www.geeksforgeeks.org/cpp/range-based-loop-c/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "scheduler.h"
#include "Schedulers/sjf.h"
#include "Schedulers/roundRobin.h"
#include "Schedulers/fcfs.h" 
#include "Schedulers/priority.h"
#include "process.h"
using namespace std;

int main(int argc, char **argv) {
    string command, response;
    int tokens;
    queue<Process> ready;

    if (argc > 1){
        commandDecider(argc, argv);
    }

    if (readFile(file, type, preemptive, ready)){
        if (type == "FCFS") {
            response += "FCFS: \n";
            FCFS(ready, verbose, response);
        } 
        else if (type == "SJF" && !preemptive) {
            response += "SJF (Non-Preemptive): \n";
            SJFNonPreemptive(ready, verbose, response);
        } 
        else if (type == "SJF" && preemptive) {
            response += "SJF (Pre-emptive): \n";
            SJFPreemptive(ready, verbose, response);
        }
        else if (type == "RR") {
            response += "Round Robin: \n";
            RoundRobin(ready, quanta, verbose, response);
        } 
        else if (type == "Priority" && !preemptive) {
            response += "Priority (Non-Preemptive): \n";
            PriorityNonPreemptive(ready, verbose, response);
        } 
        else if (type == "Priority" && preemptive) {
            response += "Priority (Preemptive): \n";
            PriorityPreemptive(ready, verbose, response);
        }
        else {
            response = "Invalid scheduling type selected";
        }
    } 
    else {
        response = "Error reading file or file is empty";
    }

    cout << response << endl;
    return 0;    
}

int commandDecider(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "--type" && i + 1 < argc) {
            type = argv[++i];
        } 
        else if (string(argv[i]) == "--preemptive") {
            preemptive = true;
        } 
        else if (string(argv[i]) == "--quanta" && i + 1 < argc) {
            quanta = atoi(argv[++i]);
        } 
        else if (string(argv[i]) == "--file" && i + 1 < argc) {
            file = argv[++i];
        } 
        else if (string(argv[i]) == "--verbose") {
            verbose = true;
        } 
        else {
            cerr << "Invalid or incomplete option: " << argv[i] << endl;
        }
    }
    return 0;
}

bool readFile(const string &filename, const string &type, const bool preemptive, queue<Process> &ready) {
    vector<Process> processes;
    ifstream file(filename);
    string line;

    if (!file) {
        return false;
    }
    
    bool empty = true;
    while (getline(file, line)) {
        empty = false;
        string idStr;
        int id, arrival, burst, priority;
        stringstream ss(line);
        ss >> idStr >> arrival >> burst >> priority;
        id = stoi(idStr.substr(2)); // removes 'P_' prefix so we can compare their integer IDs
        processes.emplace_back(id, arrival, burst, priority);
    }
    if(empty){
        return false;
    }

    sort(processes.begin(), processes.end(), compareByArrival);

    for (Process p : processes) {
        ready.push(p);
    }
    return true;
}

bool compareByArrival(const Process& a, const Process& b) {
    if (a.getArrivalTime() == b.getArrivalTime())
        return a.getId() < b.getId();
    return a.getArrivalTime() < b.getArrivalTime();
}
