#include <iostream>
using namespace std;

/**
* Test类
this 指针   ---- 每个对象都有这么一个成员变量

		存放的是当前对象的地址

		*this  当前对象
**/
class Test
{
public:
	void show()
	{
		cout << " this : " << this << endl;
	}
};


int main(int argc,char **argv)
{
	Test t;
	t.show();
	cout << " &t = " << &t << endl;
	
	return 0;
}





