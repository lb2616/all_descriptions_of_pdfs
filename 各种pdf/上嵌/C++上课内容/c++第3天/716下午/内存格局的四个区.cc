#include<iostream>
using namespace std;

class A
{
	int a;
};
class B
{
	int b;
	void show()
	{
		cout<<"hihihihihi"<<endl;// 因为放在代码段中，不计入长度，sizeof只计算数据段，栈，堆的内容
	}
};

int main(int argc,char**argv)
{
	cout<<"sizeof(A) = "<<sizeof(A)<<endl;
	cout<<"sizeof(B) = "<<sizeof(B)<<endl;
	return 0;
}
