#include <iostream>
using namespace std;
int  add(int  x = 5,int  y = 6,int  z = 3)
{
	cout <<"x = "<<x <<endl;
cout <<"y = "<<y <<endl;
cout <<"z = "<<z <<endl;
}
main( )
{   
add( );         //所有这三个参数都采用默认值
add( 1,5);     //第三个参数采用默认值
add(1,2,3);   //不使用默认值
}
