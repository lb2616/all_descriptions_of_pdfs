#include"girl.h"
int main(int agrc, char** argv)
{
	/*
	Girl g;
	g.setAge(80);
	cout<<g.getAge()<<endl;
	return 0;
	*/
	Girl g;
	Girl *p=&g;
	p->setAge(80);
	cout<<p->getAge()<<endl;
	return 0;
}

