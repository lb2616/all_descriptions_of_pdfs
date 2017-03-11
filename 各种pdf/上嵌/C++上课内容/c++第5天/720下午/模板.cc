#include<iostream>
using namespace std;

//template的功能通过模板列表 定义抽象的数据类型
template<typename T> // T 就是我们定义的抽象的数据类型
//使用 抽象数据类型 的函数 :函数模板
//函数模板 不是一个具体函数 (就像 设计图)
//当给函数模板 传递 实参的时候,函数模板就会生成一个具体的函数

T Max(T a, T b)
{
	return (a>b?a:b);
}

template<typename U>
void show(U a)
{
	cout <<"U a =" << a<<endl;
	return;
}


int main(int argc,char **argv)
{
	int i = 10;
	int j = 20;
	//调用max(i,j) ,自动生成max(int,int)
	cout << "Max(10,20) = "<<Max<int>(i,j)<<endl;//<int>为强制转换
	
	char ch1 ='c';
	char ch2 ='A';
	//调用Max(ch1,ch2) ,自动生成 Max(char,char)
	cout <<"Max('c','A') ="<<Max<char>(ch1,ch2)<<endl;
	
	double d1 = 5.63;
	double d2 = 5.42;
	//调用Max(d1,d2) ,自动生成 Max(double,double)
	
	cout <<"Max(5.63,5.43) ="<<Max<double>(5.63,5.43)<<endl;
	
	show(d1);
	
	return 0;
}

















