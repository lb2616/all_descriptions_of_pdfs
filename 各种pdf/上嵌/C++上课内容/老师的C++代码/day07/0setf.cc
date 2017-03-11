#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
/*	
	cout.width(10);
	cout.fill('*');
	cout.setf(ios::left);	// 输出内容靠左对齐
	cout << "hello" << endl;	

	cout.unsetf(ios::left);	// 取消设置
	cout.width(15);
	cout << "test" << endl;
*/	

	int i = 123;
	// 123
	cout << " dec i = " 
		<< showpos			// 显示符号   + 
		<< showbase 			// 进制前缀
		<< dec << i << endl;	// 进制输出	
	// 123 = 1*8*8(64) + 7*8(56)+3*1
	//	  =  173	8进制表示：0173
	cout << " oct i = " << oct << i << endl;
	// 123 = 7*16(112) + 11*1    10~15-> a~f
	//	  = 7b	16进制表示：0x7b
	cout << " hex i = " << hex << i << endl;

	return 0;
}











