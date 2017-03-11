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
	
	for(int i= 0;i<num.size();i++)
	{
		cout<<num[i]<<endl;
	}
	return 0;
}
