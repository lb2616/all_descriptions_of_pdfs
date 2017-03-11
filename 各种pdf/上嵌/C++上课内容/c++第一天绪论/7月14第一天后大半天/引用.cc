#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc,char **argv)
{
	int someInt;
	int	&rint = someInt;
	int intOne;
	int&rInt=intOne;
	intOne=5;
	cout<<"intOne："<<intOne<<endl;
	cout<<"rInt："<<rInt<<endl;
	rInt=7;
	cout<<"&intOne："<<&intOne<<endl;
	cout<<"&rInt："<<&rInt<<endl;
	cout<<"ha=ha"<<rInt;//endl前面一定有<<
 	return 0;
}

