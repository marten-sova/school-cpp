CC=g++
CFLAGS= -c -Wall
CXXFLAGS += -std=c++11

all: prog

prog: weatherlog.o linkedlist.o weatherdata.o datalogger.o
	$(CC) weatherlog.o linkedlist.o weatherdata.o datalogger.o -o prog

weatherlog.o: weatherlog.cpp
	$(CC) $(CFLAGS) weatherlog.cpp

linkedlist.o: linkedlist.cpp
	$(CC) $(CFLAGS) linkedlist.cpp

weatherdata.o: weatherdata.cpp
	$(CC) $(CFLAGS) weatherdata.cpp

datalogger.o: datalogger.cpp
	$(CC) $(CFLAGS) datalogger.cpp

clean:
	rm -rf *.o