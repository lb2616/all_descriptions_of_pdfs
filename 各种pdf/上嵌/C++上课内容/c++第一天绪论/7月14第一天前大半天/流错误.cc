#include<iostream>
#include<stdio.h>
using namespace std;
int main(int argc,char **argv)
{
	int grade;
	while((cin >> grade)&&(grade != -1))
		cout <<" "<<grade<<'\n';//ctrl + d 结束
	return 0;
}
