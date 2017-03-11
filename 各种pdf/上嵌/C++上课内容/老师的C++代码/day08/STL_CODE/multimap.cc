#include <iostream>
using namespace std;
#include <map>
#include <string>

int main()
{
	typedef multimap<string, string> M;
	M mss;
	M::iterator ib, ie;
	mss.insert(make_pair("aa", "bb"));
	mss.insert(make_pair("cc", "dd"));
	mss.insert(make_pair("ee", "ff"));
	mss.insert(make_pair("cc", "pp"));
	mss.insert(make_pair("aa", "mm"));
	mss.insert(make_pair("cc", "dd"));
	mss.insert(make_pair("aa", "kk"));
	ib = mss.begin();
	ie = mss.end();
	while(ib!=ie){
		cout << ib->first << "的朋友是" << ib->second << endl;
		++ib;
	}

	// count 统计含有相同key的记录个数
	cout << "aa朋友的个数:" 
		 << mss.count("aa") << endl;
	
	// lower_bound 指向 相同key的第一条记录
	// upper_bound 指向 相同key的最后一条记录
	cout << "cc:" << endl;
	ib = mss.lower_bound("cc");
	ie = mss.upper_bound("cc");
	
	while(ib!=ie){
		cout << ib->second << ' ';
		++ib;
	}
	cout << endl;
	
	
}

