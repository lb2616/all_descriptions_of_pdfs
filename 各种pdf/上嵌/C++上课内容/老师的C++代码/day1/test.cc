#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	cout << "请输入名次:" << endl;
	int iScore = 0;	//i:int 	Score:名次
	cin >> iScore;
	switch(iScore)
	{
		case 1:
			cout << "武林盟主" << endl;
			break;
		case 2:
			cout << "娶老婆" << endl;
			break;
		case 3:
			cout << "out of the door!" << endl;
			break;
		default:
			cout << "intput err!" << endl;
			break;
	}

	return 0;
}
