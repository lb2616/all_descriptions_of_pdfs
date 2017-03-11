#include<iostream>
using namespace std;
class Test;

class B
{
public:
	void fun(Test &t);
};

class Test
{
	int m_data;
public:
	Test(int data = 123):m_data(data){}
	~Test(){}
	//声明:B是Test的友元类("朋友")
	friend void B::fun(Test &t);
};

void B::fun(Test &t)
{
	cout <<"Test t.m_data = "<<t.m_data <<endl;
	return ;
}

int main(int argc,char **argv)
{
	Test t;
	B b;
	b.fun(t);
	return 0;
}
