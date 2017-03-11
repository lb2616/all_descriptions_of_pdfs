#include<iostream>
using namespace std;

class A1
{
	public:
		A1()
		{
			cout <<"A1"<<endl;
		}
		~A1()
		{
			cout << "~A1"<<endl;
		}
};

class A2
{
	public:
		A2()
		{
			cout <<"A2"<<endl;
		}
		~A2()
		{
			cout<< "~A2"<<endl;
		}
};

class A3
{
	public:
		A3()
		{
			cout <<"A3"<<endl;
		}
		~A3()
		{
			cout<<"~A3"<<endl;
		}
};

class Test :virtual public A2,public A3,virtual public A1 //加了virtual的先调用构造函数,所以A2,A1,后来才是A3
{
	public:
	Test(){cout <<"Test "<<endl;}
	~Test(){cout <<"~Test"<<endl;}
};

int main(int argc ,char **argv)
{
	Test t;
	cout <<"================="<<endl;
	return 0;
}












