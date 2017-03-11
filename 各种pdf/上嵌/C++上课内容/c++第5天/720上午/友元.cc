#include<iostream>
using namespace std;

class A
{
	int m_data;
	public:
		A(int data = 123):m_data(data){}
		~A(){}
		friend class Father;
};

class Father
{
	public:
		void fun(A &t)
		{
			cout << "A t.m_data = "<< t.m_data <<endl;
			return ;
		}
};

class Son:public Father
{
	public:
		void show(A &t)
		{ //error 
		  // 子类自己的成员方法无法访问与父类是友元关系的类的成员变量
		  //cout << A t.m_data = "<< t.m_data <<endl;
			return ;
		}
};

int main(int argc ,char **argv)
{
	A a;
	Son s;
	s.fun(a);
	cout <<"================="<<endl;
	return 0;
}












