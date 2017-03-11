#include <iostream>
using namespace std;

class Shop
{
	int m_a;
public:
	void saleDailyGoods()
	{
		cout << "卖日用品" << endl;
		return;
	}

};

class Market:public Shop	//继承:重用代码
{
public:
	void saleFood()
	{
		m_a = 10;
		cout << "食品" << endl;
		return;
	}

};

class Supermarket:public Market
{
public:
	void pay()
	{
		cout << "代缴水电费" << endl;
		return;
	}


};
int main(int argc,char **argv)
{
	Supermarket m;
	m.saleDailyGoods();
	m.saleFood();
	m.pay();
	return 0;
}
