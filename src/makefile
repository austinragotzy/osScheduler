CC = gcc

CFLAGS = -g -Wall -pedantic
#CFLAGS = -O -Wall -pedantic
main: iolist.o loopfunc.o priorityqueue.o processdef.h

iolist.o loopfunc.o priorityqueue.o: all.h

all.h: first.h iolist.h loopfunc.h priorityqueue.h processdef.h
	touch all.h

test: iolist.o loopfunc.o priorityqueue.o processdef.h

clean:
	rm -f *.o core main test

run: main
	./main a2in.txt

debug:
	gdb ./main

valgrind:
	valgrind ./main
