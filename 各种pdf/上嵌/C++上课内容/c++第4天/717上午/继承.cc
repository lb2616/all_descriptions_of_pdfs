#include<iostream>
using namespace std;
class Shop
{
public:
	void saleDailGoods()
	{
		cout <<"买日用品"<<endl;
		return ;
	}	
};

class Market:public Shop //继承:重用代码
{
public:
	void saleFood()
	{	
		cout <<"食品"<<endl;
		return;
	}
};

class Supermarket:public Market
{
public:
	void pay()
	{
		cout <<"代缴水电费"<<endl;
		return;
	}
};

int main(int argc,char **argv)
{
	Supermarket m;
	m.saleDailGoods();
	m.saleFood();
	m.pay();
	return 0;
}



