#include<iostream>
using namespace std;
class Test
{
	public:
	void show()
	{
		cout <<"this:" <<this <<endl;//this是指向这个对象的指针
	}
};

int main(int argc,char **argv)
{
	Test t;
	t.show();
	cout << "&t = " << &t <<endl;
	return 0;
}
