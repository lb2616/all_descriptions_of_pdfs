#include <iostream>
using namespace std;
#include <vector>
//20 30 40 -1
int main()
{
	vector<int> vi;
	cout << "input scores, end by -1:";
	int s;
	int m=0;
	for(;;){
		// 20 30 40 -1
		cin >> s;
		if(s==-1)
			break;
		vi.push_back(s);
		if(s>m)
			m = s;
	}
	// 20 30 40
	int inc=100-m; // inc = 60
	for(int i=0; i<vi.size(); i++)
		vi[i] += inc;
	for(int i=0; i<vi.size(); i++)
		cout << vi.at(i) << ' ';
	cout << endl;

	try{
	cout << "vi[1000]=" << vi[1000] << endl;
	cout << "vi.at(1000)=" << vi.at(1000) << endl;
	}catch(exception& e){
		cout << e.what() << endl;
	}

}





