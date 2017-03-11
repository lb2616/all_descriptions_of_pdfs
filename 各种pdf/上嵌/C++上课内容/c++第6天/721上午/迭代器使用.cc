#include<iostream>
using namespace std;

#include<vector>
void show(vector<int> vi)
{
	vector<int>::iterator it;
	it = vi.begin();
	while(it!=vi.end())
	{
		cout << *it++ <<' ';
	}
	cout <<endl;
}

int main(int argc,char **argv)
{
	vector<int> vi(3,90);
	show(vi);
	int a[5] ={3,4,5,6,7};
	vi.insert(vi.begin(),a,a+5);
	show(vi);
	vi.push_back(100);
	show(vi);
	cout<< "size = "<<vi.size() <<endl;
	vi.assign(5,99);
	show(vi);
	cout<<"size = "<<vi.size() <<endl;
	return 0;
}
