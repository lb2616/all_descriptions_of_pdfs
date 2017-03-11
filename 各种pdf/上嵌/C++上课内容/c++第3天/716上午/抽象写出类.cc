#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Waiter
{
	string m_name;//姓名
public:
	Waiter(string name):m_name(name){}
	~Waiter(){}
	string getName(){return m_name;}
	void server(int iCount,string szFood);
};

void Waiter::server(int iCount,string szFood)
{
	cout <<m_name << "上了" << iCount << "份" <<szFood <<endl;
	return;
}

class Guest
{
	string m_name;
public:
	Guest(string name):m_name(name){}
	~Guest(){}
	void order(Waiter &w);
	void pay(Waiter &w);
};

void Guest::order(Waiter &w)
{
	cout <<"******点菜过程*******"<<endl;
	int iCount = 0;
	string szFood;
	cout <<"请输入菜名:";
	cin >>szFood;
	cout <<"请输入菜的份数:";
	cin >>iCount;
	cout <<"*********************"<<endl;
	cout << m_name << "向服务员" << w.getName() << "点了" << iCount <<"份"
	<<szFood<<endl;
	
	w.server(iCount,szFood);
	return ;
}

void Guest::pay(Waiter &w)
{	
	cout << "********付款过程**********"<<endl;
	double money = 0;
	cout <<"请输入付款金额：";
	cin >>money;
	cout <<"**********************"<<endl;
	cout <<m_name<<"吃完中饭：向服务员:"<<w.getName()<<"支付了"<<money <<"元餐费，离开了老盛兴。"<<endl;
	return ;
}

int main(int argc,char **argv)
{
	Waiter w("小张");
	Guest g("小裴");
	g.order(w);
	g.pay(w);
	return 0;
}





