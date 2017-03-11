#include <iostream>
using namespace std;

class Father
{
public:
	Father(){ cout << "Father()"<< endl;}
	virtual void show(){}  //一般都是要重写的函数

	// 不虚化，子类可能存在内存泄漏
	 ~Father(){ cout << "Father()"<< endl;}
};

class Son:public Father
{
public:
	Son(){ cout << "Son()"<< endl;}
	void show(){} // 申请了 堆空间
	~Son(){ cout << "~Son()"<< endl;}  // 析构函数 释放 堆空间
};

int main(int argc,char **argv)
{
	Father *pf = new  Son;
	delete pf;
	return 0;
}








