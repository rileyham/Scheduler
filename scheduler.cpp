// scheduler.cpp
// Takes input in from user, decides which scheduler to use and sends the output

using namespace std;
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


// main
int main(int argc, char **argv) {
    string command, response;
    int tokens;
    queue<Process> ready;

    if (argc > 1){
        commandDecider(argc, argv);
    }

    ready = readFile(file, type, preemptive);
    if (type == "FCFS") {
        FCFS(ready, verbose, response);
    } 
    else if (type == "SJF" && !preemptive) {
        SJFNonPreemptive(ready, verbose, response);
    } 
    else if (type == "SJF" && preemptive) {
        SJFPreemptive(ready, verbose, response);
    }
    else if (type == "RR") {
        RoundRobin(ready, quanta, verbose, response);
    } 
    else if (type == "Priority" && !preemptive) {
        PriorityNonPreemptive(ready, verbose, response);
    } 
    else if (type == "Priority" && preemptive) {
        PriorityPreemptive(ready, verbose, response);
    }
    else {
        response = "Invalid scheduling type selected\n";
    }

    cout << response << endl;
    return 0;    
}

// commandDecider
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

// readfile
// Reads the input file and builds the process queue and sorts by a certain element
// checks if its premptive or not
queue<Process> readFile(const string &filename, const string &type, bool preemptive) {
    vector<Process> processes;
    ifstream file(filename);
    string line;
    
    while (getline(file, line)) {
        string idStr;
        int id, arrival, burst, prio;
        stringstream ss(line);
        ss >> idStr >> arrival >> burst >> prio;
        id = stoi(idStr.substr(2)); // remove 'P_'
        processes.emplace_back(id, arrival, burst, prio);
    }

    sort(processes.begin(), processes.end(), compareByArrival);

    queue<Process> ready;
    for (auto& p : processes) {
        ready.push(p);
    }
    return ready;
}


bool compareByArrival(const Process& a, const Process& b) {
    if (a.getArrivalTime() == b.getArrivalTime())
        return a.getId() < b.getId();
    return a.getArrivalTime() < b.getArrivalTime();
}
