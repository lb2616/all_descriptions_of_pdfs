#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
	// 1.打开文件
	//  打开当前目录下 ostream 文件

	// 第一种 打开文件的方式 构造函数
	//ofstream ofile("ostream",ios::app);

	// 第二种 打开文件的方式  open()
	ofstream ofile;
	ofile.open("ostream",ios::app);

	// 2.判断文件是否打开

	// 第一种 判断文件打开方式 object
	//if( NULL == ofile)

	// 第二种 判断文件打开方式 is_open()
	if( !ofile.is_open())
	{
		cout << " 打开文件 ostream 失败！！" 
			<< endl;	
		return -1;
	}
	else
	{
		cout << " 打开文件 ostream 成功！！" 
			<< endl;	
	}

	// 3.关闭文件
	ofile.close();
	
	return 0;
}
