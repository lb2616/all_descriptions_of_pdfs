#include <iostream>
using namespace std;

// template的功能 通过模板列表定义抽象的数据类型
template<typename T>  // T 就是一个抽象的数据类型
// 使用 抽象数据类型 的函数 ：函数模板
// 函数模板 不是一个具体函数 （就像 设计图）
// 当给函数模板 传递 实参的时候，函数模板就会生成一个具
// 体的函数
T Max(T a, T b)
{
	return (a>b?a:b);
}

// 无论是上面 抽象数据类型 T 还是下面 抽象数据类型 U，都是
// 人为规定的名字
template<typename U>
void Show(U a)
{
	cout << " U a = " << a << endl;
	return ;
}

int main(int argc,char **argv)
{
	int i = 10;
	int j = 20;
	Show(i);
	// 调用Max(i,j) ，自动生成  Max(int,int)
	cout << "Max(10,20) = " << Max(i,j) << endl;

	char ch1 = 'c';
	char ch2 = 'A';
	Show(ch1);
	// 调用Max(ch1,ch2) ，自动生成  Max(char,char)
	cout << "Max('c','A') = " << Max(ch1,ch2) << endl;

	double d1 = 5.62;
	double d2 = 3.43;
	Show(d1);
	// 调用Max(d1,d2) ，自动生成  Max(double,double)
	cout << "Max(5.62,3.43) = " << Max(d1,d2) << endl;

	return 0;
}
