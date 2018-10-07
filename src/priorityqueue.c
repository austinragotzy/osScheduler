#include "all.h"

int addprocess(process p, process q[], int *size){
	//add to end of the queue to be sorted
	q[*size] = p;
	(*size)++;
	return 1;
}

int tickqueue(process q[], int *size){
	int i;
	//go through and increment all the process in the queue
	for(i=0; i<*size; i++){
		q[i].wait++;
		q[i].waitSum++;
		//if wait is bigger that wait max change wait max
		if(q[i].wait>q[i].waitMax){
			q[i].waitMax = q[i].wait;
		}
	}
	return 1;
}
