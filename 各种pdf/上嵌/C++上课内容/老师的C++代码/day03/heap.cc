#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	
	// 1. 申请一块堆空间
	int *pi = 	new int;	// 申请
	*pi = 10;
	cout << " *pi = " << *pi << endl;

	/*delete pi;		// 释放 - 会自动清“零”
	cout << " delete pi; " << endl;
	cout << " *pi = " << *pi << endl;
	*/

	// 1. 申请多块连续的堆空间
	/*int *pi = 	new int[3];
	pi[0] = 1;
	pi[1] = 2;
	pi[2] = 3; 

	cout << " pi[0] " << pi[0] << endl;
	cout << " pi[1] " << pi[1] << endl;
	cout << " pi[2] " << pi[2] << endl;

	cout << " delete[] pi; " << endl;
	delete[] pi;  //  这个释放空间的语句有问题吗？？

	cout << " pi[0] " << pi[0] << endl;
	cout << " pi[1] " << pi[1] << endl;
	cout << " pi[2] " << pi[2] << endl;*/


	



	return 0;
}
