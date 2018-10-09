#include "all.h"

int tickcpu(process cpu[], os sys){
	cpu[0].curCpu++;
	cpu[0].cpuTotal++;
	return 1;
}

int kickcpu(process cpu[], process dest[], int *sizedest){
	process dummy;
	dummy.priority = 16;
	
	cpu[0].curCpu = 0;
	dest[*sizedest] = cpu[0];
	cpu[0] = dummy;
	(*sizedest)++;
	return 1;
}
