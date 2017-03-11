#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void talk()=0;
};

class Cat:public Animal
{
public:
	void talk()
	{
		cout << "喵～～～～" << endl;
		return;
	}
};

class Dog:public Animal
{
public:
	void talk()
	{
		cout << "汪～～～～" << endl;
		return;
	}
};

int main(int argc,char **argv)
{
	Cat c;
	Dog d;
	cout << "Animal *pa = &c" << endl;
	Animal *pa = &c;
	pa->talk();
	cout << "pa = &d" << endl;
	pa = &d;
	pa->talk();
	return 0;
}
