#include <iostream>
using namespace std;

class Test
{
	int m_data;
public :
	Test(int data):m_data(data)
	{
		cout << " Test() " << endl;
	}
	
	~Test()
	{
		cout << " ~Test()" << endl;
	}

	void show()
	{
		cout << " m_data = " << m_data
			<< endl;
	}
};

int main(int argc,char **argv)
{
	// 无名对象
	//Test();	// 生命周期及其短暂
	//cout << " ~~~~~~~ " << endl;

	// 1.用于创建带参的堆对象
	// new 的应用：接 类类型  或者 无名对象
	Test *pt = new Test(12); 
	pt->show();
	delete pt;

	// 2.用于数据类型的转换
	Test t1 = Test(34);
	t1.show();

	Test t2 = (Test)56;   //显式数据类型转换  ---- 用户强制
	t2.show();

	Test t3 = 78;		// 隐式数据类型转换  ---- 编译器自动
	t3.show();

	return 0;
}






