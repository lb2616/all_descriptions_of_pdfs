#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 65):m_data(data){}
	~A(){}

	void show()
	{
		cout << " m_data  = " << m_data << endl;
		return ;
	}


	void operator=(int data)
	{
		cout << " operator=(int m_data) " << endl;
		m_data = data;
		return ;
	}

	A* operator&()
	{
		cout << " A* operator&() " << endl;
		return this;
	}

	

};

int main(int argc,char **argv)
{
	//A a1 = 100; // 无名对象  拷贝构造函数
	A  a1;
	a1 = 100;  // 赋值
	a1.show();
	cout << " &a1 = " << &a1 << endl;
	return 0;
}








