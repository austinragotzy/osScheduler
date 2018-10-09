#include "all.h"
/*
name: Austin Ragotzy
class: opperating systems
assignment: Scheduling Assignment
*/
int compressarray(process a[], int index, int *size){
	//move array elements up so there is no holes
	while(index+1<*size){
		a[index] = a[index+1];
		index++;
	}
	(*size)--;
	return 1;
}

int readprocess(FILE *f, process q[], int *size){
	process p;
	if(47>*size){
		fscanf(f, "%hu %hu %hu %hu\n", &p.priority, &p.cpu, &p.io, &p.runTime);
		p.curCpu = 0;
		p.curIo = 0;
		p.wait = 0;
		p.curPrior = p.priority;
		p.cpuTotal = 0;
		p.ioTotal = 0;
		p.waitSum = 0;
		p.waitCount = 0;
		p.waitMin = 9999;
		p.waitMax = 0;
		addprocess(p, q, size);
	}

	return 1;
}

int tickclock(os sys, process cpu[], process q[], process io[], int *sizeq, int *sizeio){
	tickcpu(cpu, sys);
	tickqueue(q, sizeq, sys);
	tickio(io, sizeio);
	return 1;
}

int kickprocesses(os sys, process cpu[], process q[], process io[], process done[], int *sizeq, int *sizeio, int *sizedone){
	// if the process gets taken out of the cpu because its done
	int flag = checkdone(cpu, io, done, sizeio, sizedone);
	if(flag){
		if(*sizeq>0){
			kickqueue(q, cpu, sizeq);
		}
	//if the process gets taken out of cpu becuse it needs io
	}else if(cpu[0].curCpu>=cpu[0].cpu){
		kickcpu(cpu, io, sizeio);
		if(*sizeq>0){
			kickqueue(q, cpu, sizeq);
		}
	//if the process gets taken out because of quantum
	}else if(cpu[0].curCpu>=sys.quantum){
		kickcpu(cpu, q, sizeq);
		if(*sizeq>0){
			kickqueue(q, cpu, sizeq);
		}
	}

	kickio(io, q, sizeio, sizeq);
	return 1;
}

int checkdone(process cpu[], process io[], process done[], int *sizeio, int *sizedone){
	int ret = 0;
	int i;
	if(cpu[0].runTime<=cpu[0].ioTotal+cpu[0].cpuTotal){
		if(cpu[0].priority<16){
			done[*sizedone] = cpu[0];
			(*sizedone)++;
		}
		cpu[0].priority = 16;
		ret = 1;
	}
	for(i=0; i<*sizeio; i++){
		if(io[i].runTime<=io[i].ioTotal+io[i].cpuTotal){
			done[*sizedone] = io[i];
			compressarray(io, i, sizeio);
			//(*sizeio)--;
			(*sizedone)++;
		}
	}
	return ret;
}

int aredone(process cpu[], int *sizeq, int *sizeio){
	int ret = 0;
	if(0>=*sizeq){
		if(0>=*sizeio&&(16<=cpu[0].priority)){
			ret = 1;
		}
	}
	return ret;
}
