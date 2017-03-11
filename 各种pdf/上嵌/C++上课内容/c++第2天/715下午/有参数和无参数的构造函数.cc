#include<iostream>
using namespace std;

class A
{
	int a1;
public:
	A(int a)
	{
		a1 = a;
		cout <<"AAAA construct "<<endl;
	}
	~A()
	{
		cout <<"~~~~~~~~~~A"<<endl;
	}
	A()//若是没有这个则会编译错误,构造函数在没有定义构造函数的基础上使用默认的构造函数,如果有了,调用形式不一样,则是错误
	{
	}
};

int main(int argc,char **argv)
{
	A a;
	cout <<"========"<<endl;
	return 0;
	
}



