#include "all.h"

int addprocess(process p, process q[], int *size){
	//add to end of the queue to be sorted
	q[*size] = p;
	q[*size].waitCount++;
	(*size)++;
	return 1;
}

int tickqueue(process q[], int *size, os sys){
	int i;
	//go through and increment all the process in the queue
	for(i=0; i<*size; i++){
		q[i].wait++;
		q[i].waitSum++;
		//if wait is bigger that wait max change wait max
		if(q[i].wait>q[i].waitMax){
			q[i].waitMax = q[i].wait;
		}
		if((0 == q[i].wait%sys.wait)&&(0 != q[i].wait)){
			q[i].curPrior--;
		}
	}
	return 1;
}

int kickqueue(process q[], process dest[], int *sizeq){
	q[0].curPrior = q[0].priority;
	if(q[0].wait < q[0].waitMin){
		q[0].waitMin = q[0].wait;
	}
	q[0].wait = 0;
	dest[0] = q[0];
	compressarray(q, 0, sizeq);
	//(*sizeq)--;
	return 1;
}

int sortqueue(process q[], int *size){
	int i;
	int j;

	for(i=1; i<*size; i++){
		for(j=i-1; j>=0; j--){
			if(q[j].curPrior>q[j+1].curPrior){
				swap(q, j, j+1);
			}
		}
	}
	return 1;
}

int swap(process q[], int j, int i){
	process temp = q[j];
	q[j] = q[i];
	q[i] = temp;
	return 1;
}
