#include <iostream>
using namespace std;


inline void show(int a)//相当于替换，类似宏
{
	cout << "a = " << a << endl;
	return;


}


int main(int argc,char **argv)
{
	int i = 123;
	show(i);

	return 0;
}
