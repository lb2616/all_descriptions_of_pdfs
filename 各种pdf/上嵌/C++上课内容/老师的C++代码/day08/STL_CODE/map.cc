#include <iostream>
using namespace std;
#include <map>
#include <string>

int main()
{
	//key(是唯一的) value
	map<int, string> mis;

	// (1)插入map元素
	mis.insert(make_pair(62,"东方不败"));
	mis.insert(make_pair(32,"岳不群"));
	mis.insert(make_pair(36,"林平之"));

	// (2)插入方式 这里的20不是下标!!!!!
	mis[20] = "劳德罗";

	cout << " 插入 32 XXX" << endl;
	// key 32已经存在 这个元素插入失败
	// 2.无法插入 已存在key的记录
	mis.insert(make_pair(32,"XXX"));

	map<int, string>::iterator it;
	it = mis.begin();
	//元素的位置和 key 相关 和插入顺序没有关系
	// 1.自动排序的
	while(it!=mis.end()){
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}









