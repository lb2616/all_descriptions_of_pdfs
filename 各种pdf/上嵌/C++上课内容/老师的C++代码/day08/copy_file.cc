#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


//复制mp3或者图片文件
//  计算大小的时候，用 ifstream中gcount()函数 

//  getline()  返回值  void *


int main(int argc,char **argv)
{
	if( argc != 3)
	{
		cout << "Usge: ./copy_file a.txt b.txt "
			<< endl;
		return -1;
	}
	
	// 1.打开文件
	ifstream   ifile(argv[1],ios::in);
	ofstream ofile(argv[2],ios::out);

	// 2.判断文件是否打开
	if( !ifile || !ofile)
	{
		cout << " 打开文件失败！！" << endl;
		return -1;
	}

	char buf[128];
	while(!ifile.eof())
	{
		memset(buf,'\0',sizeof(buf));
		ifile.read(buf,sizeof(buf));	// 读文件
		// gcount() 返回 ifstream 读到的实际个数
		ofile.write(buf,ifile.gcount());	// 写文件
	}

	// 3.关闭文件
	ifile.close();
	ofile.close();

	return 0;
}
