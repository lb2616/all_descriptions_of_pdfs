#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc,char **argv)
{
	int i;
	cout <<"These are "<<argc<<" command line argument passed to main:"<<endl;
	for(i=0;i<argc;i++)
	{
		cout<<"argv"<<i<<":"<<argv[i]<<endl;
	}
	return 0;
}
