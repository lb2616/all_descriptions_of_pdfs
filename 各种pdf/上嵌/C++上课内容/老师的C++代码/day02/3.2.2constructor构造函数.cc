#include <iostream>
using namespace std;

/**
* Test类
**/
class Test
{
	int m_data;
public:
	//构造函数
	// 	1.给成员变量分配空间 -- 系统自动分配
	//	2.初始化成员变量或给成员变量赋值
	Test(int data)
	{   
		// 赋值
		m_data = data;
		cout<<"m_data" <<m_data;
	}

	void show()
	{
		cout << " m_data = " << m_data << endl;
		return ;
	}
};

int main(int argc,char **argv)
{
	// 通过对象后面的参数列表给构造函数传递实参
	Test t(12);	// 会自动调用  构造函数 Test()
	t.show();
	return 0;
}





