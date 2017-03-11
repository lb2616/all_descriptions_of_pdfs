#include<vector>
#include<iostream>
using namespace std;

vector<int> num;//
int main()
{
	int element;
	while(cin >>element)
	{
		if(element == -1)
			break;
		num.push_back(element);
	}
	
	for(vector<int>::iterator iter = num.begin();iter != num.end();++iter)
	{
		cout<<*iter<<endl;//使用iterator访问
	}
	return 0;
}
