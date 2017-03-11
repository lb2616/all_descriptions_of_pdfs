#include<stdio.h>
#include<unistd.h>

int add(int a,int b)
{
	int sum;
	__asm__ __volatile__(
		"mov r0,%1\n"
		"mov r1,%2\n"
		"swi 0x900000+365\n"
		"mov %0,r0\n"
		:"=r"(sum)
		:"r"(a),"r"(b)
		:"r0","r1"
   );
   return sum;	
}

int main()
{
	int ret;
	ret=syscall(365,2,3);
	printf("ret = %d\n",ret);
	return 0;
}
