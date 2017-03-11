#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	string s;
	cout << " 请输入一个字符串：";
	//cin >> s;
	getline(cin,s);
	cout << " string s = " << s << endl;

	return 0;
}
