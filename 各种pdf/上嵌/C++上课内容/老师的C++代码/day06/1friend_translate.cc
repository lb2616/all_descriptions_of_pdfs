#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 123):m_data(data){}
	~A(){}

	friend class B;
};

class B
{
	friend class C;
};

class C
{

public:
	void fun(A &t )
	{
		cout << " A t.m_data = " <<  t.m_data << endl;
		return ;
	}
};


int main(int argc,char **argv)
{
	A t;
	C b;
	b.fun(t);
	return 0;
}








