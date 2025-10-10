// scheduler.cpp
// Takes input in from user, decides which scheduler to use and sends the output

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "vector"
#include <fstream>
#include <sstream>
#include "scheduler.h"
#include "process.h"

// main
int main(int argc, char **argv) {
    bool running = true;
    string command, response;
    int tokens;

    if (argc > 1){
        commandDecider(argc, argv);
        cout << response;
        running = false;
    }
    cout << type << endl <<  preemptive  << endl << quanta << endl << file  << endl << verbose << endl;

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