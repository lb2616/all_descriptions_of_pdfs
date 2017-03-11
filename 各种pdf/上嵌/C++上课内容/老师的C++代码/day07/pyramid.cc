#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	int n = 0;	//	金字塔的层数
	cout << "请输入金字塔的高度：";
	cin >> n;
	
	int i;
	for(i = 1; i <= n; ++i)
	{
		cout.width(n-i); // ' '的个数
		cout.fill(' ');
		cout << "";

		cout.width(2*i -1);  //'*'的个数
		cout.fill('*');    
		cout << '*';    

		cout << endl;
	}

	return 0;
}
