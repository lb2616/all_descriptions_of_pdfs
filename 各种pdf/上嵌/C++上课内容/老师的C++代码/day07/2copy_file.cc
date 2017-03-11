#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
	// 1.打开文件
	ifstream ifile(argv[1]);
	ofstream ofile(argv[2]);
	// 2.判断文件是否打开
	if( NULL == ifile || NULL == ofile)
	{
		cout << " open file failure !!!" << endl;
		return -1;
	}
	string szContent;
	while(getline(ifile,szContent))
	{
		szContent += '\n';
		ofile.write(szContent.c_str(),szContent.size());
		//szContent.clear();
	}
	// 3.文件关闭
	ifile.close();
	ofile.close();

	return 0;
}



