#include "types.h"
#include "user.h"
#include "stddef.h"

int cpu_bound()
{
	int iterations =0;
	int max_iterations = 100000;
	int start_time=uptime();
	while (iterations < max_iterations)
	{
	// perform computation
	volatile double x = 123.456;
	for (int i = 0; i < 1000; i++)
	{
		x = x * x + x / 2.3;
	}
	
	iterations++;
	}
	int runtime = uptime()-start_time;
	return runtime;
}
int main(void)
{
	//int pid=getpid();
	int num_of_processes = 10;
	
	for (int i=0; i<num_of_processes; i++)
	{
		int pid_son=fork();
		if (pid_son==0)
			{
				setprio(getpid()%8);
				int runtime=cpu_bound();
				printf(1, "the runtime of %d with prio %d is %d\n", getpid(), getprio(), runtime);
				break;
			}
	}
	for (int i=0; i<num_of_processes; i++)
		wait();
	exit();
}
