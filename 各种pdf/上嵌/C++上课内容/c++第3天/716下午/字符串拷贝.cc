#include<iostream>
using namespace std;

class Test
{
	char *m_p;
public:
	Test()
	{
		m_p = new char;
	}
	Test(const Test &t)//一定要使用引用的方式
	{
		m_p = new char;
	}
	~Test()
	{
		delete m_p;
	}
};

int main(int argc,char **argv)
{
	Test a;
	Test b(a);
	return 0;
}
