#include <iostream>
#include <fstream>
using namespace std;

int main(int agrc,char **argv)
{
	ifstream ifile("write.txt");
	
	if( NULL == ifile)
	{
		cout << " 打开文件失败" << endl;
		return -1;
	}

	// 定位函数  - get 指针 （读指针）
	ifile.seekg(0,ios::end);

	// 指针位置函数 - get 指针 （读指针）
	cout << " get point position:" 
		<< ifile.tellg() << endl;	

	ifile.close();

	return 0;
}
