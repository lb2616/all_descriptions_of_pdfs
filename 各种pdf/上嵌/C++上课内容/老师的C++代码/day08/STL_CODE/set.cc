#include <iostream>
using namespace std;
#include <set>

int main()
{
	set<int> si;
	// 1.不允许出现重复的元素
	int userid[5]={2,8,6,1,2};
	for(int i=0; i<5; i++)
		si.insert(userid[i]);

	// 2.自动排序的
	set<int>::iterator it;
	it = si.begin();
	while(it!=si.end())
		cout << *it++ << ' ';
	cout << endl;

	// 查找元素的值，不是按下标查找！！！
	cout << "user 1:" 
      << (si.find(1)!=si.end()) << endl;
	cout << "user 2:" 
      << (si.find(2)!=si.end()) << endl;
}

