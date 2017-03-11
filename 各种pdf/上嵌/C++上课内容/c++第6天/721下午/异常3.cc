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
		A a;
		throw a;//抛出一个标识异常数据,该异常//抛出之后,throw到catch之间
		cout<<"nihaoa"<<endl;
	}
	catch(int)
	{
		cout<<"int "<<endl;
	}
	catch(A)//接收对应数据类型的异常
	{
		cout<<"AAAA "<<endl;
	}
	catch(...)//捕获人员数据类型
	{
		cout<<"有异常出现 "<<endl;
	}
	//catch()语句块执行完了,try catch后面的语句
	//依旧正常执行
	cout<< "main() process !!!!!\n";
	return 0;
}


