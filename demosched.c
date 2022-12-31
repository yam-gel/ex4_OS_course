#include "types.h"
#include "user.h"
#include "stddef.h"



int main(void)
{
	printf(1, "I am running, %d \n", getprio());
    setprio(7);
    printf(1, "I am still running, %d \n", getprio());
	//getProcInfo()
	exit();
}
