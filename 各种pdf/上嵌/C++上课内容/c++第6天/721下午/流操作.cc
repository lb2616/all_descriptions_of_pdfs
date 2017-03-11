#include<iostream>
using namespace std;
class A
{
	int m_data;
	public:
		A(int data=65):m_data(data){}
		~A(){}
		//只对类A的对象有效
		friend ostream &operator<<(ostream &os,A &a);
};

ostream &operator<<(ostream &os,A &a)
{
	os <<"[" << a.m_data <<"]";//a.m_data int 
	return os;
}

int main(int argc,char **argv)
{
	A a;
	//cout 是一个全局输出对象
	//cin是一个全局输入对象
	//cout的类类型是ostream
	//cin的类类型是istream
	cout <<" a =" << a << endl;//友元operator<<(cout,a);//成员cout.operator<<(a);
	return 0;
}
