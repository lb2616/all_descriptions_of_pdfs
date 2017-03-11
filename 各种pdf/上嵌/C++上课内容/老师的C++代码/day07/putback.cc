#include <iostream>
using namespace std;


int main(int argc,char **argv)
{
	char ch;
	cin.putback('a');
	cout << "请输入一个ch 数据：";
	cin >> ch;
	cout << " char ch = " << ch << endl;

	return 0;
}
