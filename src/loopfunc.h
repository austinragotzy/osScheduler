#ifndef LOOPFUNC
#define LOOPFUNC

int readprocess(FILE *f);
int tickclock(process cpu[], process q[], process io[]);
int checkage(process q[]);
int requeue(process q[]);
int compressarray(process a[], int index, int *size);

#endif
