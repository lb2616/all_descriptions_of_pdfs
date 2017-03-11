#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 65):m_data(data){}
	~A(){}

	// 只对 类A的对象有效
	friend ostream & operator<<(ostream &os,A &a)
	{
		os << " [ " << a.m_data << " ] " ; // a.m_data  int
		return os;
	}

};

// 想要输入或输出一个对象
//	1.数据类型的转换
//	2.重载 << >>运算符函数（常用）

int main(int argc,char **argv)
{
	A a;
	// cout 是一个全局输出对象
	// cin 是一个全局输入对象
	// cout的类类型是  ostream
	// cin的类类型是     istream
	cout << " a = "  << a << endl;	// 友员  operator<<(cout,a);
								// 成员 cout.operator<<(a);


	return 0;
}


















