#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 65):m_data(data){}
	~A(){}

	
	operator int()
	{
		return m_data;
	}
	

	operator char()
	{
		return (char)m_data;
	}

	operator bool()
	{
		return m_data != 0;
	}

	// error
	// 必须是一个普通成员函数  （非静态[代码段]的成员函数）
	/*
	friend operator int(A &a)
	{
		return a.m_data;
	}
	*/

};


// 静态函数  仅仅是限定的使用范围  --只能在本文件中使用
static void fun() 
{ 
	cout << " static void fun() " << endl;
	return ;
}




int main(int argc,char **argv)
{
	A a1;

	int i = a1;
	char ch = a1;
	bool b = a1;

	cout << " i = " << i << endl;
	cout << " ch = " << ch << endl;
	cout << " b = " << b << endl;

	fun();
	return 0;
}


/*数据类型的转换（成员）

			1.函数名：[operator] + [空格] + [数据类型]
			2.没有返回类型，但可以返回值
			3.只能用成员的方式重载*/





