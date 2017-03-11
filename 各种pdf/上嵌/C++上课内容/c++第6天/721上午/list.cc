#include<iostream>
#include<list>
using namespace std;

int main()
{
	int cpp[5]={3,4,5,6,7};
	int java[8]={6,4,7,8,15,2,3,9};
	int Unix[4]={5,2,6,9};
	list<int> li;
	li.insert(li.begin(),cpp,cpp+5);
	li.insert(li.begin(),java,java+8);
	li.insert(li.begin(),Unix,Unix+4);
	li.sort();
	li.unique();//去掉相同的数
	li.reverse();
	list<int>::iterator it = li.begin();
	while(it!=li.end())
		cout <<*it++ <<' ';
	cout <<endl;
	return 0;
	
	
};

