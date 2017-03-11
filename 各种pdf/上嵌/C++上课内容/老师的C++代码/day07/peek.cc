#include <iostream>
using namespace std;
int main(int argc,char **argv)
{
	int i;
	string s;	
	// 获得输入缓冲区中的第一个字符
	cout << "start" << endl;
	char ch  = cin.peek();	// 没有数据的时候，等待有户输入
	cout << "end" << endl;
	if( (ch >= '0') && (ch <= '9') )
	{
		//  cin >> 工作原理：当缓冲区中没有数据的时候，才等待有户输入
		//			                        有数据的时候，直接将数据存放在
		//						内存中（变量）
		cin >> i;  // "123abc"   i = 123;
		cout << " int i = " << i << endl;
	}
	else
	{
		cin >> s;
		cout << " string s = " << s << endl;
	}

	//cin >> s;
	//cout << " string s = " << s << endl;






	return 0;
}
