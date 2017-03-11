#include<iostream>
using namespace std;

class A
{
	public:
		int a1;
	public:
		int b1;
};
class B :public A
{
public:
		int b1;
};
int main(int argc,char **argv)
{
	
		try
		{
			B b;
			throw b;
		//	throw &a;//抛出一个标识异常数据,该异常
		}
/*		catch(A)//接受对应数据类型的异常
		{
			cout <<"AAAA: "<<endl;
		}*/
		catch(...)//接受对应数据类型的异常
		{
			cout <<"BBBB: "<<endl;
		}
	return 0;
}





