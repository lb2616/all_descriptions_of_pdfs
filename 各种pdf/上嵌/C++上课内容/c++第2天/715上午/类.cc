#include<iostream>
using namespace std;
class Savings
{
	public:
	float deposit(float amount)
	{
		balance+=amount;
		return balance;
	}
	void setbalance(int a)//set和get方法体现封装性
	{
		balance = a;
	}
	int getbalance()
	{
		return balance;
	}
	private:
	float balance;
};

int main(int argc,char **argv)
{
	Savings a,b;//这个是在栈上面的实例化，new是在堆上实例化
	a.setbalance(10);
	a.deposit(1000);
	cout<<a.getbalance()<<endl;
	return 0;
}

