#include "all.h"
/*
name: Austin Ragotzy
class: opperating systems
assignment: Scheduling Assignment
*/
int main(int argc, char *argv[]){
	
	process q[100];
	int sizeq = 0;
	process io[100];
	int sizeio = 0;
	process done[100];
	int sizedone = 0;
	process cpu[1];
	os sys;
	sys.quantum = 50;
	sys.wait = 50;
	int flag = 0;

	FILE *fp;
	if(!(fp = fopen("../input/a2in.txt", "r"))){
		perror("file open");
	}

	readprocess(fp, q, &sizeq);
	kickqueue(q, cpu, &sizeq);
	long int i = 0;
	while (!flag) {
		tickclock(sys, cpu, q, io, &sizeq, &sizeio);
		kickprocesses(sys, cpu, q, io, done, &sizeq, &sizeio, &sizedone);
		flag = aredone(cpu, &sizeq, &sizeio);
		sortqueue(q, &sizeq);
		if(i<47){
			readprocess(fp, q, &sizeq);
		}
		//printf("q:%d, io:%d, done:%d, iteration: %li\n", sizeq, sizeio, sizedone, i);
		i++;
	}

	printStats(done, sys);
	fclose(fp);
	return 1;
}
