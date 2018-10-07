
#include "all.h"

int kickio(process io[], process dest[], int *sizeio, int *sizedest){
	int i;
	//go through the array and find if any have finished io
	for(i=0; i<*sizeio; i++){
		if(io[i].io<=io[i].curIo){
			io[i].curIo = 0;
			addprocess(io[i], dest, sizedest);
			compressarray(io, i, sizeio);
			i--;
		}
	}
	return 1;
}
