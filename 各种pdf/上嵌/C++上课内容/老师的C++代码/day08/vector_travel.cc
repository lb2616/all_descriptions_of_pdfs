#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char **argv)
{
	// 1.vector实例化 
	/**
	* vector<elementType> vecList;                       // 无参构造函数
	* vector<elementType> vecList(otherVecList)   // 拷贝构造函数	
	* vector<elementType> vecLIst(size);		//  int  - 容器大小 
	* vector<elementType> vecList(n,elem); 		//  用n个元素初始化
	* vector<elementType> vecList(begin,end);  	// 用另外一个容器的首尾
	*									   地址初始化
	*/
	vector<int>  v(3,10);  // 容器v中装入3个元素，每个元素的值是10

	// 2.容器的遍历
	// 2-1  at() / []  +  size()
	//	size() 返回容器中元素的个数的
	cout << "容器v中的元素：";
	int i;
	for(i=0;i < v.size();++i)
	{
		cout << v.at(i) << ' ';
	}
	cout << endl;

	// 3.insert(pos,value)向容器中指定的位置插入元素
	// begin()	返回容器中第一个元素的位置(不是下标！！！！是迭代器类型)
	// end()	返回容器中最后一个元素"后面的那个位置"！！！
	cout << "insert 操作" << endl;
	v.insert(v.begin(),20);
	v.insert(v.begin(),30);
	v.insert(v.begin(),40);
	v.insert(v.end(),70);
	v.insert(v.end(),80);
	v.insert(v.end(),90);

	// 2-2  iterator + begin() + end()
	//  iterator  是一个类
	//   迭代器  ------  智能指针
	//		使用方法和指针一样，但不是指针类型！！！！
	//   不同的容器，必须使用不同的迭代器遍历
	

	// 4.迭代器对象的创建
	cout << "容器v中的元素：";
	vector<int>::iterator it;  // it 迭代器对象
	it = v.begin();
	while( it != v.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;


	// 5.容器中元素的删除
	cout << "pop_back删除元素：" << endl;
	v.pop_back();

	cout << "erase删除元素：" << endl;
	v.erase(v.begin());


	// 2-3  reverse_iterator + rbegin() + rend()
	cout << "容器v中的元素：";
	// 6.反向迭代器对象的创建
	vector<int>::reverse_iterator rit;  // it 迭代器对象
	rit = v.rbegin();
	while( rit != v.rend())
	{
		cout << *rit++ << " ";
	}
	cout << endl;

	// 8.清空容器
	cout << " v.clear() " << endl;
	v.clear();
	cout << " 容器中的元素个数：" << v.size() << endl;
	cout << " 容器是否为空：" << v.empty() << endl;



	return 0;
}















