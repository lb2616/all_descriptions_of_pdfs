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
	vector<int>::reverse_iterator ri = num.rbegin();
	while(ri != num.rend())
	{
		cout<<*ri<<" ";//使用iterator访问
		ri++;
	}
	cout<<endl;
	return 0;
}
