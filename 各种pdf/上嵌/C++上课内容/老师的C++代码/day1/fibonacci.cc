#include <iostream>
using namespace std;



int fib(int n)
{
	if(n > 2)
		return fib(n-1) + fib(n-2);
	else
		return 1;
}



int main(int argc,char **argv)
{

	cout << "n = ";
	cin >> n;
	
	cout << "n = " << fib(n) << endl;
	
	//数据不合理的时候，函数返回
	//cout << "请输入数列中要查看的位置";
	//cin >> n;
	//cout <<"第" << n <<"位置的值:" << fib(n) << endl;
	return 0;
}
