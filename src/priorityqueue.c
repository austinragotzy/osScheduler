#include "all.h"

int addprocess(process p, process q[], int *size){
	//add to end of the queue to be sorted
	q[*size] = p;
	(*size)++;
	return 1;
}
