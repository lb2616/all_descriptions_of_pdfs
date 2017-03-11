#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void eat()
	{
		cout<< "不知道吃啥"<<endl;
		return;
	}
	//virtual void eat()=0; //纯虚函数定义之后,子函数中的eat函数一定要重写,否则无法编译通过
};

class Tiger:public Animal
{
public:
	Tiger(){}
	~Tiger(){}
	void eat()
	{
		cout<<"老虎撕咬鲜肉"<<endl;
		return;
	}
};

class Rabbit:public Animal
{
public:
	Rabbit(){}
	~Rabbit(){}
	void eat()
	{
		cout<<"兔子吃青草"<<endl;
		return;
	}
};

int main(int argc,char **argv)
{
	Tiger t;
	Rabbit r;
	Animal *pa = &t;
	pa->eat();
	pa = &r;
	pa->eat();
	return 0;
}










