#ifndef CPU
#define CPU

int tickcpu(process cpu[], os sys);
int kickcpu(process cpu[], process dest[], int *sizedest);
#endif
