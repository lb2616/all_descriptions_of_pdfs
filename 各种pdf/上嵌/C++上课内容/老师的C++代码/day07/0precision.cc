#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	// 默认的有效位是6位   3.1415916    3141591.6
	// 超过6位的数字，一般用科学计数法表示
	double d = 124324123213.21341;
	double d1 = 44443.1415926100;
	cout.precision(20);
	// 对后面的输出都有效
	cout << " double d = " << d << endl;
	cout << " double d1 = " << d1 << endl;


	return 0;
}
