#include<iostream>
using namespace std;
class B0
{
public:
	virtual void display()//加在基类上,可以使得其他子类调用自己的成员函数
	{
		cout <<"B0 ::display()"<<endl;
	}
};

class B1:public B0
{
public:
	void display()
	{
		cout <<"B1:: display()"<<endl;
	}
};

class D1:public B1
{
public:
	void display()
	{
		cout<<"D1::display()"<<endl;
	}
};

void fun(B0 *ptr)
{
	ptr->display();
}

int main(int argc,char **argv)
{
	B0 b0,*p;
	B1 b1;
	D1 d1;
	p = &b0;//编译器此时只按照定义的指针来调用
	fun(p);
	p = &b1;
	fun(p);
	p = &d1;
	fun(p);
}









