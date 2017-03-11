#include <iostream>
using namespace std;

class Test
{
	// static 成员变量   --------  类变量
	//					所有该类的对象，共有的变量

public :
	static int m_data;

	Test(){}
	~Test(){}

	void setData(int data) {  m_data = data;}

	void show()
	{
		cout << "m_data = " << m_data << endl;
	}

};

// 1.只能在类的外部(全局区)进行初始化-----空间在这个点分配的
int Test::m_data = 10;


int main(int argc,char **argv)
{
	/*
	Test t;
	cout << " t.show() " << endl;
	t.show();	// 10

	Test t1;
	cout << " t1.setData(125);  " << endl;
	t1.setData(125);

	cout << " t.show() " << endl;
	t.show();		//  125
	cout << " t1.show() " << endl;
	t1.show();	// 125
	*/

	// 2.调用方式：类名::静态成员变量名
	// 3.静态成员变量的空间实在类定义的时候分配的
	//	跟对象的创建没有关系
	cout << " Test::m_data = " 
		<< Test::m_data << endl;

	Test t;
	// 虽然 可以以成员访问的方式调用 静态成员变量，
	// 但这种调用，不合理，建议大家不要使用这种
	// 调用方式
	cout << " t.m_data = " << t.m_data << endl;


	return 0;
}




