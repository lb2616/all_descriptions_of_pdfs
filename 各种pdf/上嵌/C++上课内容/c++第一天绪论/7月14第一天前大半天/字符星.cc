#include<iostream>
using namespace std;
int main(int argc,char **argv)
{
	const char *string = "test";//要加const否则报警告,把常量赋值给变量
	cout <<"value of string is :"<<string
     <<"\nvalue of static case<void *>(string)is:"
     <<(void *)(string)<<endl;
}
