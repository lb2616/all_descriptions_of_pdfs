#include<iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		cout <<"Test()"<<endl;
	}
	~Test()
	{
		cout <<"~Test()"<<endl;
	}
};

int main(int argc,char **argv)
{
	//Test *pi = new Test;
	Test *pi = new Test[3];//会调用三次构造函数
	cout << "........"<<endl;
	delete[]pi;//会调用三次析构函数
	return 0;
}
//new  和 delete要成对出现,new[]和delete[]也要成对出现
