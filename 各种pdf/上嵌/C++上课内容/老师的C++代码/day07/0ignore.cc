#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	string s;
	cout << "请输入一串字符: "; 
	// 1.忽略输入缓冲区中的前8个字符
	// 2.在前8个字符中存在 结束字符，那么就忽略
	//    输入缓冲区 结束字符 之前的字符
	cin.ignore(8,' ');	// 设置 ' '为结束字符
	cin >> s;
	cout << " string s = " << s << endl;
	

	return 0;
}
