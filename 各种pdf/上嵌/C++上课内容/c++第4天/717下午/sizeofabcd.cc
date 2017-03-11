#include<iostream>
using namespace std;
class A{};
class B{int m_j;};
class C{int m_j;void show(){}};//int 的为4
class D{int m_j;virtual void show(){};};//virtual 64位机器有一个指针占8位 内存对齐,所以为16

int main(int argc,char **argv)
{
	cout <<"sizeof(A) = "<<sizeof(A) <<endl;
	cout <<"sizeof(B) = "<<sizeof(B) <<endl;
	cout <<"sizeof(C) = "<<sizeof(C) <<endl;
	cout <<"sizeof(D) = "<<sizeof(D) <<endl;
	return 0;
}

/*运行结果
sizeof(A) = 1
sizeof(B) = 4
sizeof(C) = 4
sizeof(D) = 16
*/
