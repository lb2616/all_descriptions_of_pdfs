#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
	string s;
	//string s("weiwei");	//初始化可以带参
	//string s1(5,'a');
	//string s(s1);
	
	s = "hello shangqian!";	//1.赋值
 
 	s += "sq1409";			//2.追加/连接	
	
	s = "hello";

	s.clear();		//清空	
	cout << "size = " << s.size() << endl;	//求长度
	
	cout << "s 是否为空：" << (s.empty()?"空":"非空") << endl;//判断字符串是否为空
	
	
	
	cout << "s = " << s << endl;
	
	//string 类型 和 char *类型的转换
	const char * buf = s.c_str();
	
	//strcpy().......
	cout << "buf = " << buf << endl;
	
	//字符串比较,可以直接使用比较运算符
	//== != > < ......
	if(s == "hello")
	{
		cout << "s == hello" << endl;
	}

	//查看某个位置上的字符
	//at()越界访问 会抛出异常
	//[]  不会
	cout << "s[1] = " << s[1] << endl;	
	//cout << "s[3] = " << s.at(3) << endl;	//可以通过异常捕捉
	return 0;
}
