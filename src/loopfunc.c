#include "all.h"

int compressarray(process a[], int index, int *size){
	//move array elements up so there is no holes
	while(index+1<*size){
		a[index] = a[index+1];
		index++;
	}
	(*size)--;
	return 1;
}
