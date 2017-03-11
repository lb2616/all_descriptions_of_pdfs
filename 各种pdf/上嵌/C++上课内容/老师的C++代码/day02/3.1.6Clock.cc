/*exercise 001

	设计一个  时钟类  有 时/分/秒

		1.显示时间	12：23：59
		2.自动走秒
			每隔一秒 显示一次时间
			并且这个时间能够进位*/

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

/**
* 时钟类
**/
class Clock
{
	int m_hour;	// 小时
	int m_min;	// 分钟
	int m_sec;	// 秒钟
public:
	
	// 1.设置时间	
	void setTime(int hour,int min,int sec)
	{
		m_hour = hour;
		m_min = min;
		m_sec = sec;
		return ;
	}

	// 2.显示时间
	// 09:59:59
	// 10:00:00
	void show()
	{
		system("clear");

		if( m_hour < 10)
			cout << 0;
		cout << m_hour << ":";
	
		if( m_min < 10)
			cout << 0;
		cout << m_min << ":";

		if( m_sec < 10)
			cout << 0;
		cout << m_sec << endl;
		return ;
	}

	void tick()
	{
		sleep(1);
		++m_sec;
		if(60 == m_sec)
		{
			m_sec = 0;
			++m_min;
			if(60 == m_min)
			{
				m_min = 0;
				++m_hour;
				if(24 == m_hour)
				{
					m_hour = 0;
				}
			}
		}
		
		
	}

	// 3.时间的走动
	//     每隔一秒，显示一次时间
	void run()
	{
		while(1)
		{
			show();
			tick();
		}
	}
};

int main(int argc,char **argv)
{
	Clock  c;	
	c.setTime(23,59,55); 
	c.run();
	return 0;
}
