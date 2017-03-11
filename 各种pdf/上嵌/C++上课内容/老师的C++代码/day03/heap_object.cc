#include <stdlib.h>
#include <iostream>
using namespace std;

class Test
{
public :
	Test()
	{
		cout << " Test() " << endl;
	}
	
	~Test()
	{
		cout << " ~Test()" << endl;
	}
};

int main(int argc,char **argv)
{
	/*
	Test *pi =new Test[3];
	cout << " ... ..." << endl;
	delete[] pi;  //  这个释放空间的语句有问题吗？？
			   //         没问题，只支持对象数组的连续释放
			   //	  容器 可以解决 普通堆数组 问题	
	*/
	// void * 万能指针
	Test *pi =  (Test *)malloc( sizeof(Test));
	cout << " ... ..." << endl;
	free(pi); 

	return 0;
}
