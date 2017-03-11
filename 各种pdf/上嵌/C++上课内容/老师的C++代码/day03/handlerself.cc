#include <iostream>
using namespace std;

class Test
{
	int m_data;
public :
	Test(int data = 10):m_data(data)
	{
		cout << " Test() " << endl;
	}
	
	~Test()
	{
		cout << " ~Test()" << endl;
	}

	void show()
	{
		cout << "  m_data = "
			<< m_data << endl;
		return ;
	}
};

int main(int argc,char **argv)
{
	Test t;
	t.~Test();	 // 释放了一次
	t.show();
	return 0; // 又释放了一次
}






