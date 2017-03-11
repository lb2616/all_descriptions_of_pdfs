#include <iostream>
using namespace std;

/**
* 乐器类
**/
class Instrument
{
	string m_brand;	// 牌子
public:
	Instrument(string brand):m_brand(brand){}
	~Instrument(){}

	string getBrand(){ return m_brand;}

	virtual string method()=0;
};

/**
* 钢琴类
**/
class Piano:public Instrument
{
public:
	Piano(string brand):Instrument(brand){}
	~Piano(){}

	string method(){ return "弹";}
};

/**
* 二胡类
**/
class Erhu:public Instrument
{
public:
	Erhu(string brand):Instrument(brand){}
	~Erhu(){}

	string method(){ return "拉";}
};

/**
* 笛类
**/
class Flute:public Instrument
{
public:
	Flute(string brand):Instrument(brand){}
	~Flute(){}

	string method(){ return "吹";}
};

/**
* 演奏者类
**/
class Player
{
	string m_name;	// 姓名
public:
	Player(string name):m_name(name){}
	~Player(){}

	void play(Instrument &i,string music)
	{
		cout << m_name << " 用 " 
			<< i.getBrand() << " "
			<< i.method() <<" 了一首 "
			<< music << endl;
		return ;
	}
};



int main(int argc,char **argv)
{
	Piano p("三角钢琴");
	Erhu e("二弦二胡");
	Flute f("翠玉笛");

	Player p1("周杰伦");
	Player p2("王力宏");
	Player p3("许晴");

	p1.play(p,"肖邦的夜曲");
	p2.play(e,"二泉映月");
	p3.play(f,"笑傲江湖");


	return 0;
}







