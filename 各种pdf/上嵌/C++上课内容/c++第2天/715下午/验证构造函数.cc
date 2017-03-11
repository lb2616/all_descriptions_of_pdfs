#include<iostream>
using namespace std;

class Desk
{
public:
	Desk();
};

Desk::Desk() // 构造函数,无返回值,函数名就是类名
{
	cout <<"2222"<<endl;
}

int main(int argc,char **argv)
{
	Desk a[10];//有参数的构造函数,也可以是无参的
	return 0;
	
}

