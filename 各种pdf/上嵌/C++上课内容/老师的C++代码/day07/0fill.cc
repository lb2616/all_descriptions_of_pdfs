#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	cout.width(20);
	// 1.紧跟width()之后
	cout.fill('#');
	cout << " ShangQian " << endl;

	// 2.对 fill()之后的cout<<的语句依然有效
	cout.width(20);
	cout << " Fengyang " << endl;

	return 0;
}
