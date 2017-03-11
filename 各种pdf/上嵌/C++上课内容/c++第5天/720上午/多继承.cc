#include<iostream>
using namespace std;

class father
{
public:
	void makemoney()
	{
		cout << "会赚钱"<<endl;
		return;
	}
};

class mother
{
public:
	void face()
	{
		cout << "高挑,漂亮"<<endl;
		return;
	}
};

class son:public father,public mother
{
	
};

int main(int argc,char **argv)
{
	son s;
	s.makemoney();
	s.face();
	return 0;
}










