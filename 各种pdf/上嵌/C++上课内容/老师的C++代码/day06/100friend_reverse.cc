#include <iostream>
using namespace std;

// 绝对禁止类与类之间相互使用！！！！！！！！！！！！！

// 前置声明
class A;
class B;

// A B 声明放在一起
class A
{
	int m_data;
public:
	A(int data = 123):m_data(data){}
	~A(){}

	friend class B;
	void show(B &b);
};

class B
{
	int m_data;
public:
	B(int data = 456):m_data(data){}
	~B(){}
	friend class A;
	void show(A &a);
};

// A B的成员函数的实现放在最后

void A::show(B &b)
{
	cout << " B b.m_data = " <<  b.m_data << endl;
	return ;
}

void B::show(A &a)
{
	cout << " A a.m_data = " <<  a.m_data << endl;
	return ;
}


int main(int argc,char **argv)
{
	A a;
	B b;
	a.show(b);
	return 0;
}








