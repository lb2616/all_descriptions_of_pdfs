#include <iostream>
using namespace std;

/**
* 怪物类
为某游戏公司设计一款游戏中的怪物类

		怪物的属性

			1.名字
			2.生命力
			3.攻击力
			4.防御力

		怪物的攻击行为

			目的：让对方减少血量
		
			1.伤害值：
				
(自己的攻击力*2 -  对方的防御力 + 5）*2

	如果 这个伤害值 < 1,设置 伤害值为1		

			2.描述攻击过程

	例如： 怪物A攻击 怪物B，让B掉了多少点血



	设计完成之后，大家创建2个怪物

	让这2个怪物对打（回合值），其中一个怪物

	的生命值 <=0 ,战斗结束
**/
class Monster
{
	string m_name;	// 兽名
	int m_hitpoint;	// 生命值
	int m_damage;	// 攻击值
	int m_defense;	// 防御值
public:
	Monster(string name,int hitpoint,int damage,int defense)
			:m_name(name),m_hitpoint(hitpoint),
			m_damage(damage),m_defense(defense){}
	~Monster(){}

	int getHitpoint(){  return m_hitpoint;}
	string getName(){ return m_name;}

	// 攻击行为
	void attack(Monster &m)
	{
		// 1.计算伤害值
		int iHurt = 0;
		iHurt = 2*(m_damage*2 - m.m_defense + 5);
		if( iHurt <=  0)
			iHurt = 1;

		// 2.减去对方的生命值
		 m.m_hitpoint -= iHurt;

		// 3.描述攻击过程
		cout << m_name << " 攻击 " << m.m_name
			<< " 让 " << m.m_name << " 掉了 "
			<< iHurt << " 血！！ " << endl;

		return ;
	}

};



int main(int argc,char **argv)
{
	Monster m1("旺财",8888,400,250);
	Monster m2("小花",6666,300,300);


	while(1)
	{
		m1.attack(m2);
		if(m2.getHitpoint() <=0)
		{
			cout << m2.getName() 
				<< " 被打死了！！" << endl;
		
			break;
		}
			

		m2.attack(m1);
		if(m1.getHitpoint() <=0)
		{
			cout << m1.getName() 
				<< " 被打死了！！" << endl;
		
			break;
		}

	}

	return 0;
}





