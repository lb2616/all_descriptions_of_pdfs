#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 123):m_data(data){}
	~A(){}

	
// a++
int operator++(int) // int 形参只为标识++在后，没其他的作用
{
	int tmp = m_data;
	m_data += 1;
	return tmp;
}

// ++a
int operator++()
{
	++m_data;  // 默认运算符函数
	return m_data;
}

};



int main(int argc,char **argv)
{
	A a1;
	int iResult = a1++; 
	cout << " iResult = " << iResult << endl;
	return 0;
}








