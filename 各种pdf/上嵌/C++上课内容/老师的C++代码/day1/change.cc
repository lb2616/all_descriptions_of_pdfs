#include <iostream>
using namespace std;

//指针实现
/*void Change(int *iValue)
{
	*iValue += 10;
	return;

}*/

//引用实现
void Change(int &iValue)
{
	iValue += 10;
	return;

}
int main(int argc,char **argv)
{
	char *string = "test";
cout << "Value of string is: "<< string
     << "\nValue of static cast< void *>( string ) is:"
      << (void*)( string )<<endl;
	
	return 0;
}
