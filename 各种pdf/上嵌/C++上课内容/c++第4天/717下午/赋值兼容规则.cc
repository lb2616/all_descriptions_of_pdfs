#include<iostream>
using namespace std;

class Father
{
public:
	Father(){cout <<"Father()"<<endl;}
	~Father(){cout <<"~Father()"<<endl;}
	void show()
	{
		cout <<"Father::show()" <<endl;
	}
};

class Son:public Father //继承:重用代码
{
public:
	Son(){cout <<"Son()" <<endl;}
	~Son(){cout <<"~Son()"<<endl;}
	void print()
	{
		cout << "Son::print()" <<endl;
	}
};


int main(int argc,char **argv)
{
	Son s;
	Father f =s;//调用拷贝构造函数,没有打印father的构造函数,因为没有拷贝构造函数,系统调用了无参的拷贝构造函数
	f.show();
	Father *pf = &s;
	pf->show();
	s.print();//pf->print();不能用father的指针调用print()函数
	Father &rf = s;
	rf.show();
	return 0;
}
/*
	运行结果:
	Father()
	Son()
	Father::show()
	Father::show()
	Son::print()
	Father::show()
	~Father()  析构f
	~Son()     析构s
	~Father()  析构s中的father
*/
