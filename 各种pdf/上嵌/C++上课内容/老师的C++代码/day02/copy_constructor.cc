#include <iostream>
using namespace std;

class Test
{
	int m_data;
public:
	Test(int data):m_data(data){}
	// 拷贝构造函数的形式
	Test(Test &t)
	{
		m_data = t.m_data;
		cout << " Test(Test &t) " << endl;
	}
	~Test(){}

	void show()
	{
		cout << " m_data = " << m_data << endl;
	}
};

int main(int argc,char **argv)
{
	// 对象的创建 ：
	//    1.通过  参数列表 创建
	Test t(10);

	//   2. 通过 一个已有的对象 创建
	//Test t1 = t;	//  将 t中成员变量的值 拷贝一份赋给了
				//  t1中的成员变量
	Test t1(t);
	t1.show();

	

	return 0;
}




