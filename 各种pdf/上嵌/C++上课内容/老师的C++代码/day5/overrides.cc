#include <iostream>
using namespace std;


class Father
{

public:
	
	
	virtual void show()
	{
		cout << "Father::show()" << endl;
	}

};


class SonA:public Father	//继承:重用代码
{
public:
	
	
	void show()
	{
		cout << "SonA::show()" << endl;
	}

};

class SonB:public Father	//继承:重用代码
{
public:
	
	
	void show()
	{
		cout << "SonB::show()" << endl;
	}

};


int main(int argc,char **argv)
{
	SonA sa;
	SonB sb;
	
	Father *pf = &sa;
	
	pf->show();	//调用的是SonA的虚表
	
	pf=&sb;
	pf->show();
		
	return 0;
}
