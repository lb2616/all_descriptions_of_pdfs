#include <iostream>
using namespace std;


class Father
{
public:
	void makemoney()
	{
		cout << "会赚钱" << endl;
		return;	
	}
};

class Mother
{
public:
	void face()
	{
		cout << "高挑，漂亮" << endl;
		return;
	
	}
};

class Son:public Father,public Mother
{


};


int main(int argc,char **argv)
{
	Son s;
	s.makemoney();
	s.face();
	return 0;
}
