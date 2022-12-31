#include "types.h"
#include "user.h"
#include "stddef.h"


int main(void)
{
	int pid=getpid();
	int num_of_processes = 8;
	printf(1, "I am running, %d \n", getprio());
    setprio(7);
    printf(1, "I am still running, %d \n", getprio());
	for (int x=0; x<num_of_processes; x++)
	{
		if (pid <  0)
		printf(1, "error\n");
		if (pid == 0)
		{
			setprio(getpid()%8);
			long long int counter=0;
			for (int i=0; i<100000000; i++)
				for (int j=0; j<10000000; j++)
					for (int k=0; k<500000000; k++) //the later processes do more operations
						counter++;
			if (x==num_of_processes-1)
			{
			counter=0;
			for (int i=0; i<500000002; i++)
				for (int j=0; j<100000000; j++)
					for (int k=0; k<500000000; k++) //the later processes do more operations
						{counter++;
						sleep(0.1);}
			}
			printf(1, "pid: %d prio: %d\n", getpid(),getprio());
			break;
		}
		if (pid > 0)
		{
			pid=fork();
		}
	}
	for (int x=0; x<num_of_processes; x++)
	{
		if (pid==0)
			break;
		printf(1, "the %d process to finish is with prio: %d\n", x, wait());
	}
	//getProcInfo()
	exit();
}
