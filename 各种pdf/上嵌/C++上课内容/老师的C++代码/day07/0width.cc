#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	// 1.width()一般放在 cout << 之前
	cout.width(30);
	// 输出的字符串默认是靠右
	// 功能：设置输出内容宽度，不足的位置用空格填充
	// 2.width仅仅对它下一条cout<<语句有效
	cout << "welcome to fengyang!!!" <<endl;

	// 按默认的方式输出
	cout << " fengyang OK!!!" << endl;
	return 0;
}








