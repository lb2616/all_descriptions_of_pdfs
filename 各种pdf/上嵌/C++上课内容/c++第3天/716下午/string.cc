#include<iostream>
using namespace std;

int main(int argc,char **agrv)
{
	string s;
	
	s = "hello shangqian!";//赋值
	s += "qh12443";
	s = "hello";
	//s.clear();
	cout <<"size = "<<s.size()<<endl;//求长度
	cout << "s 是否为空："<<(s.empty()?"空":"非空")<<endl;//判断字符串是否为空
	cout << "s = "<<s<<endl;
	//string 类型和char *类型转换
	const char *buf = s.c_str();
	//strcpy...
	cout <<"buf = "<<buf <<endl;
	//字符串比较，可以直接使用比较运算符
	// == != ><.....
	
	if(s == "hello")
	{
		cout <<"s== hello"<<endl;
	}
	
	//查看某个位置上的字符
	//at（）越界访问会抛出异常
	//[]不会
	cout <<"s[1] = "<<s[1] <<endl;
	cout <<"s[3]= "<<s.at(3)<<endl;
	return 0;
}






