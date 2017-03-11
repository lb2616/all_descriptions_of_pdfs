#include <iostream>
using namespace std;

class Plural
{
	int m_true_part;
	int m_empty_part;
public:
	Plural(int true_part,int empty_part):m_true_part(true_part),m_empty_part(empty_part){}
	~Plural(){}
	
	friend int operator+(Plural &p1,Plural &p2);
	
	friend int operator+(Plural &p1,Plural &p2);
	
	
};

int operator+(Plural &p1,Plural &p2)
{
	return p1.m_true_part += p2.m_true_part;
}

int operator-(Plural &p1,Plural &p2)
{
	return p1.m_empty_part + p2.m_empty_part;
}


int main(int argc,char **argv)
{	

		
	return 0;
}
