#include <iostream>
using namespace std;

/**
* 分数类
设计一个分数类  Fraction

		这个类包含  分子  分母

	1.通过构造函数，设置 分子和分母的值
	2.打印分式   print()  形式：2 / 3
	3.约分	   redu()  12 / 16   ---->  3 / 4	

	12 16
	范围：[1,12]
	1 2 4
	
	从后先前遍历，第一能同时被12和16整除的数
	一定是 它们的最大公约数
**/
class Fract
{
	int m_n;	// 分子
	int m_d;   // 分母
public:
	// 1.通过构造函数，设置 分子和分母的值
	Fract(int n,int d):m_n(n),m_d(d)
	{
		cout << " m_n = " << m_n << endl;
		cout << " m_d = " << m_d << endl;
	}

	~Fract(){}

	// 2.打印分式
	void print()
	{
		redu();
		cout << m_n << " / " << m_d << endl;
		return ;
	}

	// 3.约分
	void redu()
	{
		int i;
		for(i = m_d; i >0 ; --i)
		{
			if( (m_n%i == 0)  &&
			     (m_d%i == 0))
			{
				m_n /= i;
				m_d /= i;
				break;
			}
		}

		return ;
	}
};


int main(int argc,char **argv)
{
	Fract f(6,2);
	f.print();
	return 0;
}




