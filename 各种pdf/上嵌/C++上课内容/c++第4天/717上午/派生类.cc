#include<iostream>
using namespace std;

class Father
{
public:
	Father(){cout <<"Father()"<<endl;}
	~Father(){cout <<"~Father()"<<endl;}
	void show()
	{
		cout <<"Father::show()" <<endl;
	}
};

class Son:public Father //继承:重用代码
{
public:
	Son(){cout <<"Son()" <<endl;}
	~Son(){cout <<"~Son()"<<endl;}
	void print()
	{
		cout << "Son::print()" <<endl;
	}
};

int main(int argc,char **argv)
{
	Son s;
	return 0;
}
