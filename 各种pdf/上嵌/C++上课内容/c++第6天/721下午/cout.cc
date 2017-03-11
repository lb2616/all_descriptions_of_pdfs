/*
输出流注意事项
	上例中输出的顺序有如下规律：
	计算顺序： 自右向左
	输出顺序： 自左向右
	cout 在执行时相当于一个函数，而即将输出的4 个fun( ) 函数相当参数，编译器在函数调用时的入栈顺序是从右向左的，所以在指向fun( )函数时，依次从右向左执行，执行完fun（ ）函数之后，cout输出各个参数返回的值，此时又是从左至右进行输出，所以函数的执行结果为：4321
*/

#include<iostream>
using namespace std;
int g=0;
int fun() 
{
	return ++g;
}

int main(int argc, char **argv)
{
	cout<<fun()<<fun()<<fun()<<fun()<<endl;//先计算最后的为1,最前面一个为4
	return 0;
}
