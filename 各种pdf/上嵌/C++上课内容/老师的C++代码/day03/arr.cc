#include <iostream>
using namespace std;
//错误啊

class Test
{
	int m_data[3];
public :
	// 编译器一般把 形参中的 数组 当作 指针处理
	// 数组 不是 基本数据类型 ，是复合
	Test(int data[3]):m_data(data)
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
	int arr[3] = {0,1,2};
	Test t(arr);
	

	
	return 0; // 又释放了一次
}






