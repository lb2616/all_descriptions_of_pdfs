#include <iostream>
using namespace std;

/**
* Test类
**/
class Test
{
	// 普通成员变量既可以直接赋值，也可以使用初始化列表
	//int i;
	//double d;
	
	// 一些特殊的成员变量只能用初始化列表
	// 例如：常成员变量  引用成员变量 等
	const int m_i ;
	int &m_ri;
public:
	//构造函数
	// 	1.给成员变量分配空间 -- 系统自动分配
	//	2.初始化成员变量或给成员变量赋值
	Test(int data,int rdata):m_i(data),m_ri(rdata)
	{   
		// error 不使用初始化列表，直接赋值会报错
		// m_i = data;
		// m_ri = rdata; 
		cout << " m_i = " << m_i << endl;
		cout << " m_ri = " << m_ri << endl;
	}

	// 析构函数
	//	1.释放成员变量的空间
	//	2.对象消亡的时候，会自动调用
	~Test()
	{   
		cout << " ～Test() " << endl;
	}
};


int main(int argc,char **argv)
{
	int i = 20;
	int j = 30;
	Test t(20,30);	// 自动调用 构造函数

	cout << " main() " << endl;
	
	return 0;  // 局部对象 t 在 return 的时候消亡，
			 //  这个时候，t会自动调用 析构函数
}



