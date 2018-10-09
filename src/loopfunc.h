#ifndef LOOPFUNC
#define LOOPFUNC
/*
name: Austin Ragotzy
class: opperating systems
assignment: Scheduling Assignment
*/
int readprocess(FILE *f, process q[], int *size);
int tickclock(os sys, process cpu[], process q[], process io[], int *sizeq, int *sizeio);
int kickprocesses(os sys, process cpu[], process q[], process io[], process done[], int *sizeq, int *sizeio, int *sizedone);
int checkdone(process cpu[], process io[], process done[], int *sizeio, int *sizedone);
int compressarray(process a[], int index, int *size);
int aredone(process cpu[], int *sizeq, int *sizeio);

#endif
