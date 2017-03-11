#include<iostream>
#include<stdio.h>
using namespace std;
const int* const p1;//指针和值均不能变
const int* p2;      //指针不能变
int* const p3;      //值不能变

int main(int argc,char **argv)
{
	int a = 10;
	const int* p2 = &a;//int const *p2 = &a;
	*p2 = 12;
	return 0;
}
