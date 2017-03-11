#include<iostream>
using namespace std;

class Desk
{
public:
	Desk(int a,int b,int c,int d);
public:
	int weight,height,width,length;
};

Desk::Desk(int a,int b,int c,int d) // 构造函数,无返回值,函数名就是类名
{
		weight = a;
		height = b;
		width = c;
		length = d;//构造函数也可以重载
}

int main(int argc,char **argv)
{
	Desk a(10,20,30,40);//有参数的构造函数,也可以是无参的
	cout <<a.weight<<" "<<a.height<<" " <<a.width<<" "<<a.length<<" "<<endl;
	return 0;
	
}

