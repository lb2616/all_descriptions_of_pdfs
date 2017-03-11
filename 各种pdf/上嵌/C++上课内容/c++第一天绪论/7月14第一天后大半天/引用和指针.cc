#include<iostream>
#include<stdio.h>
using namespace std;

void swap_point(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap_ref(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(int argc,char **argv)
{
	int a = 10;
	int b = 20;
	cout <<"a,b "<<a<<" "<<b<<endl;
	swap_point(&a,&b);
	cout <<"a,b "<<a<<" "<<b<<endl;
	swap_ref(a,b);
	cout <<"a,b "<<a<<" "<<b<<endl;
	return 0;
	
}
