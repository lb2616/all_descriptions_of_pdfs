#include <iostream>
using namespace std;
class A
{
public:
	int a1;
};
class B :public A
{
public:
	int b1;
};
int main(int argc,char **argv)
{
	try
	{
		B b;
		throw b;	// 抛出一个标识异常数据，该异常
						// 抛出后，throw到 catch之间
						// 的语句就不再执行

	}
	catch(B)	// 接受对应数据类型的异常
	{
		cout << " BBBB " << endl;
	}
	catch(A)	// 接受对应数据类型的异常
	{
		cout << " AAAA" << endl;
	}	
	catch(...)	// 捕获任意数据类型
	{
		cout << " 有异常出现 " << endl;
	}
	

	// catch（）语句块执行完了，try catch后面的语句
	// 依旧正常执行
	cout << " main() process !!!" << endl;
	

	return 0;
}
