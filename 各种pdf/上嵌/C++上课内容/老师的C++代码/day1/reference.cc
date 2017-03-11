#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	int i = 0;
	//3.引用必须在初始化的时候，指定要引用的对象
	int &ri = i;	//声明ri是变量i的引用（别名）
	
	//error
	//int &ri;
	//ri = i;
	
	cout << "i = " << i << endl;
	cout << "ri = " << ri << endl;
	
	//1.操作引用，就是操作引用对应变量的本身
	ri += 10;
	cout << "ri += 10" <<endl;
	cout << "i = " << i << endl;
	cout << "ri = " << ri << endl;
	
	//2.引用本身不占内存空间
	cout << "&i = " << &i << endl;
	cout << "&ri = " << &ri << endl;
	
	
	return 0;
}
