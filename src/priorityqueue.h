
#ifndef PRIOITYQUEUE
#define PRIOITYQUEUE
#include "first.h"
int addprocess(process p, process q[], int *size);
int tickqueue(process q[]);
int adjustpriority(process q[]);
int sortqueue(process q[]);
int kickqueue(process q[], process dest[]);

#endif
