#include<iostream>
#include<stdio.h>
using namespace std;
namespace Graphics
{
	const int nlibary = 1;
};
namespace system
{
	const int nlibary = 2;
};
using namespace Graphics;
using namespace system;
int main(int argc,char **argv)
{
	cout <<system::nlibary<< endl;//否则就存在二义性,否则编译不通过
	return 0;//要指明nlibary是哪个的成员
}

