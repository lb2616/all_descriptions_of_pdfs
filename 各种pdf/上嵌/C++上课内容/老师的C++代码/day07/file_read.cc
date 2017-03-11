#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
	// 1.打开文件
	ifstream ifile("write.txt");

	// 2.判断文件是否打开
	if( NULL == ifile)
	{
		cout << " 打开文件 失败" << endl;
		return -1;
	}

	
	string name;
	int age;
	string college;

	//第一种 读 ifstream  >> 格式化读文件  
	//	这种读 ，会自动忽略空格
	//ifile >> name >> age >> college;
		

	//第二种 读 ifstream  read()
	//char buf[32] = {0};
	//ifile.read(buf,32);


	//第三种 读 ifstream  getline  /  全局的 getline
	//ifile.getline(buf,sizeof(buf));
	string s;
	getline(ifile,s);

/*	
	cout << " name = " << name << endl;
	cout << " age = " << age << endl;
	cout << " college = " << college << endl;
	*/

	//cout << " buf = " << buf << endl;
	cout << "  s = " << s << endl;

	//3.关闭文件
	ifile.close();

	return 0;
}
