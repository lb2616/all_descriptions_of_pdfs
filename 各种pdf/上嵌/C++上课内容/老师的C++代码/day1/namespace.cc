#include <iostream>
using namespace std;


//A和B是程序员自己定义的名字空间
//std是库里面提供的名字空间

namespace A
{
	int a = 10;
}


namespace B
{
	int a = 20;
}


int main(int argc,char **argv)
{
	//：：域作用符
	//A：：a 告诉编译器 这里的a是属于名词空间A的
	cout << "A中的a = " << A::a << endl;
	cout << "B中的a = " << B::a << endl;
	return 0;
}
