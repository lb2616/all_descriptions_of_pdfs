#include<iostream>
using namespace std;

class A
{
public:
	A();
	~A()
	{
		cout <<"~~~~~~~~~~A"<<endl;
	}
};

A::A()
{
	cout <<"AAAA construct "<<endl;
}

class Desk
{
public:
	Desk();
	~Desk()
	{
		cout<<"~~~~~~~~~~Desk"<<endl;
	}
	A a;
};

Desk::Desk() // 构造函数,无返回值,函数名就是类名
{
	cout <<"desk construct "<<endl;
}


int main(int argc,char **argv)
{
	Desk d;
	cout <<"--------"<<endl;
	A a;
	cout <<"========"<<endl;
	return 0;
	
}



