#include<stdio.h>
#include<unistd.h>

void buzzer(int flag)
{
	int sum;
	__asm__ __volatile__(
		"mov r0,%0\n"
		"swi 0x900000+366\n"
		"mov %0,r0\n"
		:
		:"r"(flag)
		:"r0"
   );	
}

int main()
{
	while(1)
	{
		buzzer(0);
		sleep(1);
		syscall(366,1);
		sleep(1);
	}
	return 0;
}
