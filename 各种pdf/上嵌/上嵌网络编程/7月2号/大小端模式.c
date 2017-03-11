#include<stdio.h>
int main()
{
	short int x;
	char x0,x1;
	x0=((char *)&x)[0];
	x1=((char *)&x)[1];
	printf("%x,%x\n",x,x0);
	return 0;
}
