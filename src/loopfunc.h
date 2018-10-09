#ifndef LOOPFUNC
#define LOOPFUNC

int readprocess(FILE *f, process q[], int *size);
int tickclock(os sys, process cpu[], process q[], process io[], int *sizeq, int *sizeio);
int kickprocesses(os sys, process cpu[], process q[], process io[], process done[], int *sizeq, int *sizeio, int *sizedone);
//int requeue(process q[]);
int checkdone(process cpu[], process io[], process done[], int *sizeio, int *sizedone);
int compressarray(process a[], int index, int *size);
int aredone(process cpu[], int *sizeq, int *sizeio);

#endif
