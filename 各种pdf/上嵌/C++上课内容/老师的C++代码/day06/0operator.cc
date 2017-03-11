#include <iostream>
using namespace std;

class A
{
	int m_data;
public:
	A(int data = 123):m_data(data){}
	~A(){}
	// 成员
	int operator+(A &a)
	{
		return m_data + a.m_data;
	}
	// 友员
	//friend int operator+(A &a1,A &a2);	
};
/*int operator+(A &a1,A &a2)
{
	return a1.m_data + a2.m_data;
}*/
int main(int argc,char **argv)
{
	A a1;
	A a2;
	int iResult = a1 + a2;  // 友员： operator+(a1,a2);
					  //  成员：a1.operator+(a2);
	cout << " iResult = " << iResult << endl;
	return 0;
}








