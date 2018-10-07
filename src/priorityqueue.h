
#ifndef PRIOITYQUEUE
#define PRIOITYQUEUE
#include "first.h"
int addprocess(process p, process q[], int *size);
int tickqueue(process q[], int *size, os sys);
//int adjustpriority(process q);
int sortqueue(process q[], int *size);
int kickqueue(process q[], process dest[], int *sizeq);
int swap(process q[], int j, int i);
#endif
