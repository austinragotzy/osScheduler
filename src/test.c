#include "all.h"

int main(int argc, char *argv[]){
	process a1[6];
	process cpu[1];
	process p;
	os sys;
	sys.quantum = 50;
	sys.wait = 50;
	p.io = 3;
	p.curIo = 1;
	a1[0]=p;
	a1[1]=p;
	a1[2]=p;
	a1[3]=p;
	a1[4]=p;
	a1[5]=p;
	a1[0].curPrior=4;
	a1[1].curPrior=10;
	a1[2].curPrior=5;
	a1[3].curPrior=7;
	a1[4].curPrior=5;
	a1[5].curPrior=2;
	a1[0].curCpu=1;
	a1[1].curCpu=2;
	a1[2].curCpu=3;
	a1[3].curCpu=4;
	a1[4].curCpu=5;
	a1[5].curCpu=6;
	a1[1].io=5;
	a1[1].curIo=5;
	int s1 = 6;
	process a2[6];
	a2[0]=p;
	a2[1]=p;
	int s2 = 2;
	kickio(a1, a2, &s1, &s2);
	a2[0].priority = 5;
	a2[0].curPrior = a2[0].priority;
	a2[0].wait = 49;
	tickio(a1, &s1);
	tickqueue(a2, &s2, sys);
	printf("priority was 5 now is :%d\n", a2[0].curPrior);
	kickqueue(a2, cpu, &s2);
	printf("priority 5: %d, cur priority 6: %d\n", cpu[0].priority, cpu[0].curPrior);
	int i;
	for(i=0; i<s1; i++){
		printf("%d). priority: %d  curCpu: %d\n", i, a1[i].curPrior, a1[i].curCpu);
	}
	sortqueue(a1, &s1);
	for(i=0; i<s1; i++){
		printf("%d). priority: %d  curCpu: %d\n", i, a1[i].curPrior, a1[i].curCpu);
	}
	printf("you did it\n");
	return 1;
}
