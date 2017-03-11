#include <iostream>
#include <vector>
using namespace std;


void travel(vector<int>  &v)
{
	int i;
	for(i=0;i < v.size();++i)
	{
		cout << v.at(i) << ' ';
	}
	cout << endl;
}

int main(int argc,char **argv)
{

	vector<int>  v1(5,10); 
	vector<int>  v2(3,20); 

	cout << " 交换之前：";
	cout << "容器v1中的元素：";
	travel(v1);
	cout << "容器v2中的元素：";
	travel(v2);

	v1.swap(v2);

	cout << " 交换之后：";
	cout << "容器v1中的元素：";
	travel(v1);
	cout << "容器v2中的元素：";
	travel(v2);

	



	return 0;
}















