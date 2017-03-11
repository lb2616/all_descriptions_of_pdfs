#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "string"
using namespace std;

int main(int argc,char **argv)
{
	// 1.打开文件
	ifstream ifile("example1");

	// 2.判断文件是否打开
	if( NULL == ifile)
	{
		cout << " 打开文件 失败" << endl;
		return -1;
	}

	// 第一种 循环读
	/*
	string s;
	while( getline(ifile,s))  // 返回的是读到的数据个数
	{
		cout << " s = " << s << endl;
	}
	

	// 第二种 循环读
	string s;
	while( !ifile.eof())  
	{
		getline(ifile,s);
		cout << " s = " << s << endl;
	}
	*/

	
	// 第三种 循环读
	string name;
	int age;
	string college;

	
	while( 1 )  
	{
		ifile >> name >> age >> college;

		if(ifile.eof())
			break;

		cout << name << " "
			<< age << " "
			<< college << endl; 
	}


	
	//3.关闭文件
	ifile.close();

	return 0;
}
