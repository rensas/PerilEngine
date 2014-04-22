CFLAGS=-std=c++11

all: execs

execs: test.o Point.o Octnode.o Octree.o
	g++ test.o Point.o Octnode.o Octree.o -w -o test_run $(CFLAGS)

test.o: test.cpp Point.h Octnode.h Octree.h
	g++ -w -c test.cpp

Point.o: Point.cpp
	g++ -c Point.cpp

Octnode.o: Octnode.cpp
	g++ -c Octnode.cpp

Octree.o: Octree.cpp
	g++ -c Octree.cpp
clean:
	rm -f *.o
	rm -f test_run
