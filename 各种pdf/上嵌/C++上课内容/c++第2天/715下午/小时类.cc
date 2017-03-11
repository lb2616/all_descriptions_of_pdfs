#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

class Clock
{
	int m_hour;
	int m_min;
	int m_sec;
public:
	void setTime(int hour,int min,int sec)
	{
		 m_hour=hour;
		 m_min=min;
		 m_sec=sec;
	}
	void show()
	{
		system("clear");
		if(m_hour<10)
		{
			cout <<"0"<<m_hour;
		}
		else
			cout <<m_hour;
		cout<<":";
		if(m_min<10)
		{
			cout <<"0"<<m_min;
		}
		else
			cout <<m_min;
		cout<<":";
		if(m_sec<10)
		{
			cout <<"0"<<m_sec;
		}
		else
			cout <<m_sec;
		cout <<endl;
		
	}
	
	void tick()
	{
		sleep(1);
		++m_sec;
		if(60==m_sec)
		{
			m_sec = 0;
			m_min++;
			if(m_min == 60)
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
};

int main(int argc,char **argv)
{
	Clock c;
	c.setTime(23,59,53);
	while(1)
	{
		c.tick();
		c.show();
	}
}




