#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	char m[20];
	//string s;	// 成员的getline只能给char []赋值
	cin.getline(m,20);	// 20 表示 接受字符的个数 (19)+ '\0'
	cout<<m<<endl;
}
