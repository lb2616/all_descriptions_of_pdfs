#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> num;
int main()
{
	int element;
	while(cin>>element)
	{
		if(element == -1)//或者按ctrl+d
			break;
		num.push_back(element);
	}
	
	for(vector<int>::iterator iter = num.begin();iter !=num.end();)
	{
		if(*iter == 13)
		{
			iter = num.erase(iter);//返回下一个位置的迭代器
		}
		else
		{
			++iter;
		}
	}
	
	for(vector<int>::iterator iter = num.begin();iter !=num.end();++iter)
		cout <<*iter<<' ';
	cout<<endl;
}
