#include <iostream>
using namespace std;

//1.enum包含的是 符号常量
//2.符号常量的值默认从0开始，依次加1
//3.也可以给某个符号设置值，该符号后面的符号的值在这个新值的基础上依次加1
//bool中的true false 也是符号常量
enum{Mon,Tue,Wen};

//应用：
//	企业程序中，一般很少用常量，用符号常量来替代
//	尤其是在switch case中


int main(int argc ,char **argv)
{
	cout << "Mon =" << Mon << endl;
	cout << "Tue =" << Tue << endl;
	cout << "Wen =" << Wen << endl;
	return 0;
}
