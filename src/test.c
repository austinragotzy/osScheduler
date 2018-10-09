#include "all.h"

int main(int argc, char *argv[]){
	process q[100];
	int sizeq = 0;
	process io[100];
	int sizeio = 0;
	process cpu[1];
	FILE *fp;
	if(!(fp = fopen("../input/a2in.txt", "r"))){
		perror("file open");
	}
	readprocess(fp, q, &sizeq);
	printf("priority: %d, io: %d\n", q[0].priority, q[0].io);
}
