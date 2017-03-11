#include <iostream>
using namespace std;


class A
{
	int m_a;
	int m_c;
public:
	A(int a,int c):m_a(a),m_c(c){}
	~A(){}
	
	void show()
	{
		cout << "A::show() m_a = " << m_a << endl;
		cout << "A::show() m_c = " << m_c << endl;
		return;
	}

};

class B
{
	int m_b;
	A acls;	//让A的对象a作为B的成员变量
public:
	//成员对象必须用初始化列表初始化
	//以下情况可以不使用初始化列表
	//	1.成员对象的构造函数是无参的
	//	2.成员对象的构造函数的所有形参都有默认值
	B(int a,int b,int c):m_b(b),acls(a,c){}	//传给对象的构造函数
	~B(){}
	
	void show()
	{
		acls.show();
		cout << "B::show() m_b = " << m_b << endl;
		return;
	}

};


int main(int argc,char **argv)
{
	B b(1,2,3);
	
	b.show();
	
	
	return 0;
}
