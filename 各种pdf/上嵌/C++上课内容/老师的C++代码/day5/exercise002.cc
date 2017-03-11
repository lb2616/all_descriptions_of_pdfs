#include <iostream>
using namespace std;



class Animal
{
public:
	virtual void eat()
	{
		cout << "" << endl;
		return;
	}
};

class Tiger:public Animal
{

public:
	Tiger(){}
	~Tiger(){}
	
	void eat()
	{
		cout << "老虎撕咬鲜肉" << endl;
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
		cout << "兔子咀嚼青草" << endl;
		return;
	}
	

};


class People
{
	string m_name;
public:
	People(string name):m_name(name){}
	~People(){}
	
	void givefood(string animal,string food)
	{
		cout << m_name << "给" << animal << "喂" << food << endl;
		return;
	}
};

int main(int argc,char **argv)
{
	People p("饲养员");
	p.givefood("老虎","鲜肉");
	p.givefood("兔子","青草");
	
	Tiger t;
	Rabbit r;
	
	Animal *pa = &t;
	pa->eat();
	
	pa = &r;
	pa->eat();
		
	return 0;
}
