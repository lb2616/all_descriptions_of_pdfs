#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc,char **argv)
{
	bool bSex = true;
	cout << "请输入性别:";
	cin >>bSex;
	cout << "我叫jack,是一位"<< (bSex?"帅哥":"美女")
	<<endl;
	
	cout << "true = "<<true <<endl;
	cout << "false = "<<false <<endl;
	
	return 0;
}
