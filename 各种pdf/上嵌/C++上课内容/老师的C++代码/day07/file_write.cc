#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
	// 1.打开文件
	ofstream ofile("write.txt",ios::app); // append

	// 2.判断文件是否打开
	if( NULL == ofile)
	{
		cout << " 打开文件 失败" << endl;
		return -1;
	}

	//第一种 写 ofstream  << 
	/*
	ofile << "小虎" << " " 
		<< 18 << " "
		<< "网络工程" << endl;

	ofile << "小熊" << " " 
		<< 22 << " "
		<< "电子技术" << endl;
	*/
	//第二种 写 ofstream  write(char*,int len)
	string buf("吴峰 19 电子技术"); 
	ofile.write(buf.c_str(),buf.size()); 
	
	//3.关闭文件
	ofile.close();

	return 0;
}




