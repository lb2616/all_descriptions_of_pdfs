#include <iostream>
using namespace std;

class Father
{

public:
	Father(){cout << "Father()" << endl;}
	~Father(){cout << "~Father()" << endl;}
	

};


class Member
{
public:
	Member(){cout << "Member()" << endl;}
	~Member(){cout << "Member()" << endl;}

};

class Son:public Father	//继承:重用代码
{
public:
	Son(){cout << "Son()" << endl;}	//通过父类的构造函数
	~Son(){cout << "~Son()" << endl;}

};
int main(int argc,char **argv)
{
	Son s;

	
	return 0;
}
