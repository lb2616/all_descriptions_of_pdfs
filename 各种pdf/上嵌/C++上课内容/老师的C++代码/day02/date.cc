#include <iostream>
using namespace std;

int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


/**
* 日期类
设计一个日期类   Date

		年  月  日

	1.通过构造函数，设置 年 / 月 / 日的值
	2.打印分式   print()  形式：2014-08-05
	3.判断闰年   bool isLeapYear()  
	4.求  2014-08-05 这一天 是 今年的第 多少 天
		int DayOfYear()
**/
class Date
{
	int m_year;	//   年
	int m_month;   //  月
	int m_day;	//  日
public:
	Date(int year,int month,int day):m_year(year),m_month(month),m_day(day){}
	~Date(){}

	int getYear(){ return m_year;}

	void print()
	{	
		
		cout << m_year<< "-";

		if( m_month < 10)
			cout << 0;
		cout << m_month<< "-";

		if( m_day < 10)
			cout << 0;
		cout << m_day << endl;
		return ;
	}

	// 用来 判断 的成员函数 
	// 返回值  一般是  bool 
	// 函数名 以 is开头
	bool isLeapYear()
	{
		return  (  ( (m_year%4 == 0) && 
			          (m_year%100 !=0)  )  || 
			    (m_year%400 == 0) );
	}

	//  2014-08-05
	int DayOfYear()
	{
		int sum = 0;
		// 1.求m_month之前 几个月的天数总和
		int i;
		for(i=0;i<m_month-1;++i)
		{
			sum += arr[i];
		}

		// 2.处理2月份天数问题
		if( m_month > 2)
			sum += isLeapYear();

		// 3.在以上基础上 加上 m_day
		sum += m_day;

		return sum;
	}
};


int main(int argc,char **argv)
{
	Date d(2000,3,1);
	d.print();
	cout << d.getYear() << " 是闰年吗？"
		<< (d.isLeapYear()?"是":"不是" )
		<< endl;

	cout << " 是今年的第  "<< d.DayOfYear()
		<< " 天 " << endl;
	
	return 0;
}




