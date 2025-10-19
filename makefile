# Make File for Scheduler

scheduler: scheduler.o priority.o process.o roundRobin.o fcfs.o sjf.o
	g++ scheduler.o priority.o process.o roundRobin.o fcfs.o sjf.o -o scheduler

scheduler.o: scheduler.h scheduler.cpp 
	g++ -c scheduler.cpp -o scheduler.o

priority.o: Schedulers/priority.h Schedulers/priority.cpp
	g++ -c Schedulers/priority.cpp -o priority.o

process.o: process.h process.cpp
	g++ -c process.cpp -o process.o

roundRobin.o: Schedulers/roundRobin.h Schedulers/roundRobin.cpp
	g++ -c Schedulers/roundRobin.cpp -o roundRobin.o

fcfs.o: Schedulers/fcfs.h Schedulers/fcfs.cpp
	g++ -c Schedulers/fcfs.cpp -o fcfs.o

sjf.o: Schedulers/sjf.h Schedulers/sjf.cpp Schedulers/priority.h Schedulers/priority.cpp
	g++ -c Schedulers/sjf.cpp -o sjf.o

