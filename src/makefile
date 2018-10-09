CC = gcc

CFLAGS = -g -Wall -pedantic
#CFLAGS = -O -Wall -pedantic
main: iolist.o loopfunc.o priorityqueue.o cpu.o printStats.o

iolist.o loopfunc.o priorityqueue.o printStats.o: all.h

all.h: first.h iolist.h loopfunc.h priorityqueue.h cpu.h a2.h
	touch all.h

clean:
	rm -f *.o core main

run: main
	./main

debug:
	gdb ./main

valgrind:
	valgrind ./main
