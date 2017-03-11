#include <iostream>
using namespace std;

// 多个抽象数据类型的定义，用逗号隔开
template<class T,class U>
class Test
{
	// 1.成员变量可以使用抽象的数据类型
	T m_t;	
	U m_u;
public:
	Test(T t,U u):m_t(t),m_u(u){}
	~Test(){}

	void show()
	{
		cout << " T m_t = " << m_t << endl;
		cout << " U m_u = " << m_u << endl;
		return ;
	}

	// 2.成员函数的形参也可以使用抽象的数据类型
	void print(T,U);
};

// Test实例化后具体数据类型就是W,V
template<class T,class U>
void Test<T,U>::print(T w,U v)
{
	cout << " W w = " << w << endl;
	cout << " V v  =" << v << endl;
	return ;
}

int main(int argc,char **argv)
{
	// 将类模板实例化
	Test<int,double> t(10,3.14);
	t.show();
	t.print(45,3.334);

	return 0;
}
