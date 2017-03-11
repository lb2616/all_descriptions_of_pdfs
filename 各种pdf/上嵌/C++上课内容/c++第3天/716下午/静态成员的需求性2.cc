#include<iostream>
using namespace std;

class Test
{
	//static 成员变量---类变量
	//所有该类的对象,共用的变量
public:
	static int m_data;
	Test(){}
	~Test(){}
	void setData(int data){m_data = data;}
	void show()
	{
		cout <<"m_data = "<<m_data<<endl;
	}
};

int Test::m_data = 10;
int main(int argc ,char **argv)
{
	
	cout <<"1m_data = "<<Test::m_data <<endl;
	Test t2;
	cout <<"2m_data = "<<t2.m_data<<endl;
	return 0;
}













