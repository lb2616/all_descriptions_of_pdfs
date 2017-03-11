#include<iostream>
#include<stdio.h>

using namespace std;
int main(int argc,char **argv)
{
	char buffer[100] = {0};
	cin.getline(buffer,100);
	cout<<buffer<<endl;
	return 0;
}

