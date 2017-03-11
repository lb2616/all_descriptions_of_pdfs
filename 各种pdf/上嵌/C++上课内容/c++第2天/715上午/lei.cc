/*
#include<iostream>
#include<stdio.h>
using namespace std;

class Girl
{
	private:
	int m_age;
	public:
	void setAge(int age)
	{
		m_age = age;
		return ;
	}
	int getAge()
	{
		return m_age;
	}
};

int main(int agrc, char** argv)
{
	Girl g;
	g.setAge(19);
	cout<<g.getAge()<<endl;
	return 0;
}

*/
//下面的是比较标准的写法
#include<iostream>
#include<stdio.h>
using namespace std;

class Girl
{
	private:
	int m_age;
	public:
	void setAge(int age);
	int getAge();
	
};

void Girl::setAge(int age)
	{
		m_age = age;
		return ;
	}
	int Girl::getAge()
	{
		return m_age;
	}

int main(int agrc, char** argv)
{
	Girl g;
	g.setAge(19);
	cout<<g.getAge()<<endl;
	return 0;
}

