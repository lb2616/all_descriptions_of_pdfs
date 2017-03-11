#include<iostream>
using namespace std;

class A
{
public:
	~A()
	{
		cout<< "~~~~~~A     "<<a1<<endl;
	}
	A(int w)
	{
		a1 = w;cout<<"A construct    "<<a1<<endl;
	}
	int a1;
};
class Desk
{
	public:
	~Desk()
	{
		cout<<"~~~~~Desk"<<endl;
	}
	Desk():b(12),a(10)//一定要对构造函数初始化,使用初始化列表
	{
		cout<<"Desk construct "<<endl;
	}
	A a;//a一定在b之前构造的
	A b;
};

int main(int argc,char **argv)
{
	Desk t;
	cout << "====="<<endl;
	return 0;
}






