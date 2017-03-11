#include <iostream>
using namespace std;

class A{};
class B{int m_i;};
class C{int m_i;void show(){}};
class D{int m_i;virtual void show(){}};
int main(int argc,char **argv)
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;
	return 0;
}
