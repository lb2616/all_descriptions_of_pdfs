#include<stdio.h>

int main(int argc,char *argv[])
{
	unsigned short n= 0x1234;
	unsigned char *m = (unsigned char * )&n;
	if(*m==0x34)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

