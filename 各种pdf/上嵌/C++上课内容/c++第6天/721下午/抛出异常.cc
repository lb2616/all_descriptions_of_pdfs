#include<iostream>
using namespace std;

class A
{
	public:
		int a1;
};

int main(int argc,char **argv)
{
	try
	{
		try
		{
			A a;
			a.a1=1;
			throw &a;//抛出一个标识异常数据,该异常
		}
		catch(A* w)//接受对应数据类型的异常
		{
			cout <<"AAAA: "<<w->a1 <<endl;
			w->a1= 20;
			throw;
		}
	}
	catch(A* w)//接受对应数据类型的异常
	{ 
		cout <<"AAAA: "<<w->a1 <<endl;
	}
	return 0;
}





