#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char **argv)
{
	//1.打开不存在的文件

	//ofstream ofile("c.txt");			// ok
	//ifstream ifile("d.txt");		   	//  fail

	//ofstream ofile("a.txt",ios::app);  	 // ok
	//ifstream ifile("b.txt",ios::app);	    	// ok

	//ofstream ofile("e.txt",ios::in);		// fail
	//ifstream ifile("f.txt",ios::in);		// fail

	//ofstream ofile("m.txt",ios::out);       // ok
	//ifstream ifile("n.txt",ios::out);		//  fail

	//ofstream ofile("i.txt",ios::trunc);	// ok
	//ifstream ifile("j.txt",ios::trunc);	// fail

	ofstream ofile("x.txt",ios::binary);	// ok
	ifstream ifile("y.txt",ios::binary);        // fail 

	// 2.判断文件是否打开
	if( !ofile.is_open())
	{
		cout << " ofile 打开文件失败！！" 
			<< endl;	
	}

	if( !ifile.is_open())
	{
		cout << " ifile 打开文件失败！！" 
			<< endl;	
	}
	
	// 3.关闭文件
	ofile.close();
	ifile.close();
	
	return 0;
}




