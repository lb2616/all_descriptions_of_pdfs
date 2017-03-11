#include <iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv)
{
ofstream ofile("example",ios::out | ios::binary);
if( !ofile.is_open() ) {
	cout<<"open failed"<<endl;
	return 0;
}
int a = 10;
ofile.write((char*)&a, sizeof(int));
ofile.close();

ifstream ifile("example", ios::in | ios::binary);
if( !ifile.is_open() ) {
	cout<<"open failed"<<endl;
	return 0;
}
int b;
ifile.read((char*)&b, sizeof(int)); //读取格式与写入格式要对应
cout<<" the file content is:"<<b<<endl;
ifile.close();
	return 0;
}





