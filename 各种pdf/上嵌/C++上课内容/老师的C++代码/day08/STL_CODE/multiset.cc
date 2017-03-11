#include <iostream>
using namespace std;
#include <set>

template<typename Iter>
void show(Iter ib, Iter ie)
{
	while(ib!=ie)
		cout << *ib++ << ' ';
	cout << endl;
}

int main()
{
	int a[5]={5,1,7,5,1};
	multiset<int> pids(a, a+5);

	show(pids.begin(), pids.end());
	
	pids.insert(7);
	pids.insert(7);
	pids.insert(7);
	// find() 返回找到元素第一次出现的位置
	pids.erase(pids.find(5));	// 迭代器类型

	show(pids.begin(), pids.end());

	cout << "end process 7..."<<endl;
	// erase() 传递值的，会将该容器中所有的这个值
	// 全部删除
	pids.erase(7);			// int

	show(pids.begin(), pids.end());
}

