#include <iostream>
using namespace std;
class Test
{
public:
	virtual void show() = 0;
};
class Sort:public Test
{
public:
	void show()
	{
		cout << "Sort::show()" << endl;
		return;
	}
};
int main(int argc,char **argv)
{
	Sort t;
	t.show();
	return 0;
}
