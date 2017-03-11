#include <iostream>
using namespace std;

class Test
{
	int m_data;
public:
	Test(int data):m_data(data)
	{
		cout << " Test("<<m_data<<") " << endl;
	}

	~Test()
	{
		cout << " ~Test("<<m_data<<") " << endl;
	}
	
};
Test t1(10);  // 全局对象
void fun()
{
	Test t4(40);
	return ;
}
void show()
{
	static Test t5(50);	// 静态对象
	return ;
}
int main(int argc,char **argv)
{
	Test t2(20);
	Test t3(30);
	fun();	// Test t4(40);  // 局部对象
	show();	// static Test t5(50);  // 静态对象
	return 0;  // t1先析构？还是t2先析构
}
Test t6(60);  // 全局对象



