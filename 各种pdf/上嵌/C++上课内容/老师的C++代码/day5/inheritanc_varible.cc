#include <iostream>
using namespace std;

class Father
{
	int m_a;
	int m_b;
public:
	Father(int a,int b):m_a(a),m_b(b){}
	~Father(){}
	
	void show()
	{
		cout << "Father::show() m_a = " << m_a << endl;
		cout << "Father::show() m_b = " << m_b << endl;
		return;
	}

};

class Son:public Father	//继承:重用代码
{
public:
	Son(int a,int b):Father(a,b){}	//通过父类的构造函数
	~Son(){}

};
int main(int argc,char **argv)
{
	Son s(1,2);
	s.show();
	
	return 0;
}
