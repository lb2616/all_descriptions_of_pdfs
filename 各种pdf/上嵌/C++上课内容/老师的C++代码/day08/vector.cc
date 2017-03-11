#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char **argv)
{
	// 1.容器类模板的实例化
	//		顺序容器的类模板只有一个抽象数据类型
	vector<int> v; // 容器对象 v中的元素都是 int

	// 2.元素的插入
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	// 3.元素的查询
	cout << "容器对象v中的第一个元素的值是：" << v.front() << endl;
	cout << "容器对象v中的最后一个元素的值是：" << v.back() << endl;
	cout << "容器对象v中的下标为1的元素的值是：" << v.at(1) << endl;
	cout << "容器对象v中的下标为2的元素的值是：" << v[2] << endl;

	return 0;
}









