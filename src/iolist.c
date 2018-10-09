#include "all.h"
/*
name: Austin Ragotzy
class: opperating systems
assignment: Scheduling Assignment
*/
int kickio(process io[], process dest[], int *sizeio, int *sizedest){
	int i;
	//go through the array and find if any have finished io
	for(i=0; i<*sizeio; i++){
		if(io[i].io<=io[i].curIo){
			io[i].curIo = 0;
			addprocess(io[i], dest, sizedest);
			compressarray(io, i, sizeio);
			i--;
			//(*sizeio)--;
		}
	}
	return 1;
}

int tickio(process io[], int *size){
	int i;
	for(i=0; i<*size; i++){
		io[i].curIo++;
		io[i].ioTotal++;
	}
	return 1;
}
