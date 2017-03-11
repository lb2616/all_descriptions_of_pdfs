#include <iostream>
using namespace std;

/**
* 怪物类
**/
class Monster
{
	string m_name;	// 兽名
	int m_hitpoint;	// 当前生命值
	int m_damage;	// 攻击值
	int m_defense;	// 防御值

	int m_orihitpoint;	//初始生命值
protected:

	int GetHurtValue(int defense)
	{
		// 1.计算基本伤害
		int iHurt = 0;
		iHurt = 2*(m_damage*2 - defense + 5);
	
		//2.计算实际伤害
		if( m_hitpoint <= m_orihitpoint*0.8  && m_hitpoint >= m_orihitpoint*0.6)
				iHurt *=  0.75;
		else if(  m_hitpoint < m_orihitpoint*0.6  && m_hitpoint >= m_orihitpoint*0.2 )
				iHurt *=  0.5;
		else if( m_hitpoint < m_orihitpoint*0.2 )
				iHurt *= 100;

		// 3.最小伤害值处理
		if( iHurt <=  0)
			iHurt = 1;
			
		return iHurt;
	}




public:
	Monster(string name,int hitpoint,int damage,int defense):m_name(name),m_hitpoint(hitpoint),m_damage(damage),m_defense(defense),m_orihitpoint(hitpoint){}
	~Monster(){}

	int getHitpoint(){  return m_hitpoint;}
	string getName(){ return m_name;}

	// 1.攻击行为
	void attack(Monster &m)
	{
		// 1.计算伤害值
		int iHurt = GetHurtValue(m.m_defense);

		// 2.减去对方的生命值
		 m.m_hitpoint -= iHurt;

		// 3.描述攻击过程
		cout << m_name << " 攻击 " << m.m_name
			<< " 让 " << m.m_name << " 掉了 "
			<< iHurt << " 血！！ " << endl;

		return ;
	}

// 2.战斗过程
void fight(Monster &m)
{
		int iCount = 0;
		while(1)
		{
			cout << " 第 " << ++iCount <<" 回合" << endl;

			attack(m);
			if(m.getHitpoint() <=0)
			{
				m.m_hitpoint = 0;
				cout << m.getName() 
						<< " 被打死了！！" << endl;
				break;
			}
			m.attack(*this);
			if(getHitpoint() <=0)
			{
					m_hitpoint = 0;
					cout << getName() 
							<< " 被打死了！！" << endl;
					break;
			}
		} // end while()

		show();
		m.show();
} // end fight()

// 3.显示怪物属性
void show()
{
	cout << "**********怪物属性**********"<< endl;
	cout << "  姓  名：" << m_name << endl;
	cout << "  生命值：" << m_hitpoint << endl;
	cout << "  攻击值：" << m_damage << endl;
	cout << "  防御值：" << m_defense << endl;
	cout << "****************************"<< endl;
	return ;
}



};



int main(int argc,char **argv)
{
	Monster m1("旺财",8888,400,250);
	Monster m2("小花",6666,300,300);

	m2.fight(m1);
	

	return 0;
}





