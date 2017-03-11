#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
	//申请一块空间
	/*
	int *pi = new int;//申请一块
	*pi = 10;
	cout << "*pi = "<<*pi <<endl;
	delete pi;    //释放会自动清零
	cout <<"delete pi;"<<endl;
	cout <<"*pi = "<<*pi <<endl;
	*/
	//申请多块连续的堆空间
	int *pi = new int[3];
	pi[0] = 1;
	pi[1] = 2;
	pi[2] = 3;
	
	cout <<"pi[0] "<<pi[0] <<endl;
	cout <<"pi[1] "<<pi[1] <<endl;
	cout <<"pi[2] "<<pi[2] <<endl;
	cout <<"delete[] pi:" <<endl;
	delete[]pi;//这个释放的空间的语句有问题吗???
	
	cout <<"pi[0] "<<pi[0] <<endl;
	cout <<"pi[1] "<<pi[1] <<endl;
	cout <<"pi[2] "<<pi[2] <<endl;
	return 0;
}
