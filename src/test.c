#include "all.h"

int main(int argc, char *argv[]){
	process a1[6];
	process p;
	p.io = 3;
	p.curIo = 1;
	a1[0]=p;
	a1[1]=p;
	a1[2]=p;
	a1[3]=p;
	a1[4]=p;
	a1[5]=p;
	a1[1].io=5;
	a1[1].curIo=5;
	int s1 = 6;
	process a2[6];
	int s2 = 0;
	kickio(a1, a2, &s1, &s2);
	tickio(a1, &s1);
	tickqueue(a2, &s2);
	printf("you did it\n");
	return 1;
}
