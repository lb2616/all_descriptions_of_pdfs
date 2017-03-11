#include <iostream>
using namespace std;

/**
* 侠客类
**/
class Swordsman
{
	string m_name;		// 姓名
	bool m_state;			// 身体状况
public:
	Swordsman(string name,bool state = true):m_name(name),m_state(state){}
	~Swordsman(){}

	void attack(Swordsman &s);// 1.偷袭
	void check(Swordsman &s);	// 2.诊断
};

// 1.偷袭
void Swordsman::attack(Swordsman &s)
{
	cout << m_name << "  偷袭了 " 
			<< s.m_name << endl;

	s.m_state = false;
	return ;
}

// 2.诊断
void Swordsman::check(Swordsman &s)
{
	cout << "经 "   << m_name << " 诊断  " 
			<< s.m_name << (s.m_state?"无大碍":"受伤了 ") << endl;
	return ;
}

int main(int argc,char **argv)
{
	Swordsman s1("张无忌");
	Swordsman s2("令狐冲");
	Swordsman s3("平一指");

	s1.attack(s2);
	s3.check(s2);

	return 0;
}
