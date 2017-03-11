#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

/**
* 炸弹类
设计一个定时炸弹类

		1.可以设置 定时炸弹 的时间

		2.炸弹到00：00：00的时候爆炸

			Bomb~~~~~~~~~~~~~
**/
class Bomb
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

	// 00:00:05
	// 00:01:05
	// 01:00:05
	int tick()
	{
		sleep(1);	
		--m_sec;
		if(  ( 0 == m_sec) && 
		      ( 0 == m_min) &&
			( 0 == m_hour ) )
			return 0;
		if(-1 == m_sec)
		{
			m_sec = 59;
			--m_min;
			if(-1 == m_min)
			{
				m_min = 59;
				--m_hour;
			}
		}
		return 1;
	}

	// 3.时间的走动
	//     每隔一秒，显示一次时间
	void run()
	{
		while(1)
		{
			show();
			if(!tick())
				break;
		}
		show();	
		cout << " Bomb~~~~~~~~~" << endl;
	}
};

int main(int argc,char **argv)
{
	Bomb  b;	
	b.setTime(0,0,5); 
	b.run();
	return 0;
}
