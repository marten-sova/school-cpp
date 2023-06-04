CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = rover.h queue.h stack.h resultdata.h
QOBJ = queue.o
SOBJ = stack.o
OBJ = rover.o rovercontrol.o scandata.o resultdata.o $(QOBJ) $(SOBJ)

%.o: %c $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ 

rovercontrol: $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

testrover: rovercontrol
	./rovercontrol commands.txt > tmp.txt
	diff tmp.txt expected.txt > diffout.txt

testqueue: $(QOBJ) testqueue.cpp
	$(CC) $(CPPFLAGS) -g -o $@ $^
	./testqueue

teststack: $(SOBJ) teststack.cpp
	$(CC) $(CPPFLAGS) -g -o $@ $^
	./teststack








