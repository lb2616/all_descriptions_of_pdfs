#include <iostream>
using namespace std;

class Seller
{
	string m_name;
	
public:
	string m_thing;
	Seller(string name):m_name(name){}
	~Seller(){}
	
	string getName(){return m_name;}
	
	//发货
	void send(string name,int iCount)	//b未声明
	{
		cout << m_name << "给" 
			<< name << "发了"
			<< iCount << "双" << m_thing << endl;
			
		return; 
	}

};


class Buyer
{

	string m_name;
	bool m_good;

public:
	Buyer(string name,bool good = true):m_name(name){}
	
	~Buyer(){}
	
	string getName(){return m_name;}
	
	void order(Seller &s)	//
	{
		cout << "*********订购过程*********" << endl;
		int iCount = 0;		// 物品的份数

		cout << "请输入物品名：";
		cin >>s.m_thing;

		cout << "请输入物品的份数：";
		cin >>iCount;

		cout << "**************************" << endl;

		cout << m_name <<  "在" 
			<< s.getName() << " 订购了 "  
			<< iCount << " 双 "
			<< s.m_thing << endl;

		// 卖家发货
		s.send(m_name,iCount);
		
		cout << "请输入你是否满意?";
		cin >> m_good;
		return;
	}
	
	//付款
	void pay(Seller &s)
	{
		cout << m_name << "对" << s.m_thing << (m_good?"很满意":"不满意")
			<< "于是" << (m_good?"支付了贷款":"就退货了")
			<< endl;
			return;
	
	}


};


int main(int argc,char **argv)
{
	Seller s("京东商城");
	Buyer b("艾米");
	
	b.order(s);
	b.pay(s);
	
	
	return 0;
}
