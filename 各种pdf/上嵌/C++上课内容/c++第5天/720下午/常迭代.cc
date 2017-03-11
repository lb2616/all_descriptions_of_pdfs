//常迭代
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
	
	for(vector<int>::const_iterator iter = num.begin();iter != num.end();++iter)
	{
		cout<<*iter<<" ";//使用iterator访问
		
	}
	cout<<endl;
	return 0;
}
