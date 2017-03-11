#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
/*
	char buffer[5] = {0};
	cout << "请输入一串字符：";
	cin >> buffer;
	cout << " buffer = " << buffer << endl;
*/



	cout << " good = " << cin.good() << endl;
	cout << "    fail = " << cin.fail() << endl;

	char buffer[10] = {0};
	cout << "请输入一串字符：";
	cin.getline(buffer,10);
	cout << " buffer = " << buffer << endl;

	cout << " good = " << cin.good() << endl;
	cout << "    fail = " << cin.fail() << endl;


	cin.clear();	// 清楚输入流的错误状态

	char buffer1[10] = {0};
	cout << "请输入一串字符：";
	cin.getline(buffer1,10);
	cout << " buffer1 = " << buffer1 << endl;

	cout << " good = " << cin.good() << endl;
	cout << "    fail = " << cin.fail() << endl;


	return 0;
}
