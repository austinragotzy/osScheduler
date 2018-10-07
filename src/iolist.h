#ifndef IOLIST
#define IOLIST

int tickio(process io[], int *size);
int kickio(process io[], process dest[], int *sizeio, int *sizedest);

#endif
