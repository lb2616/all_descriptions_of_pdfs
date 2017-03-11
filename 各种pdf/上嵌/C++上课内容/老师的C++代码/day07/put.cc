#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	// put(char) 
	// 1.输出单个字符
	cout.put('a');
	cout.put('b');
	cout.put('c');
	cout.put('\n');

	// 2.可以连续输出
	cout.put('e').put('e').put('e').put('e').put('\n');
	
	return 0;
}
