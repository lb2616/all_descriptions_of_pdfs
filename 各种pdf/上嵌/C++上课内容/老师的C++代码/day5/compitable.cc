#include <iostream>
#include <iostream>
using namespace std;
class Father
{
public:
	Father(){cout << "Father()" << endl;}
	~Father(){cout << "~Father()" << endl;}
	
	void show()
	{
		cout << "Father::show()" << endl;
	}

};
class Son:public Father	//继承:重用代码
{
public:
	Son(){cout << "Son()" << endl;}	//通过父类的构造函数
	~Son(){cout << "~Son()" << endl;}
	
	void print()
	{
		cout << "Son::print()" << endl;
	}

};


int main(int argc,char **argv)
{
	Son s;
	
	/*Father f =s;
	f.show();
	
	Father *pf = &s;	//指针
	pf->show();
	
	Father &rf = s;
	rf.show();
*/
	
	return 0;
}
