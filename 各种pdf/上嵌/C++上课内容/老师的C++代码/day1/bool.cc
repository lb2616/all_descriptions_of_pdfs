#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	bool bSex = true;
	//true 和 false 是枚举类型中的 符号常量
	//从键盘上获得bool类型的值，输入0(false)和1(true)即可
	//备注：在键盘上输入true 和 false
	//编译器一般会把它当字符串处理，不同的编译器结果可能不同
	//编译器：非0为真，0为假
	cout << "请输入性别:";
	cin >> bSex;
	cout << "我叫jack，是一位" << (bSex?"帅锅":"美女") 
	<< endl;

	cout << "true =" << true << endl;
	cout << "false =" << false << endl;

	return 0;
}
