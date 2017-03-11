#include <iostream>
using namespace std;
double & fn(const double & pd)
{
    static double ad = 3;
	ad += pd;
	cout << "fn being called .. the value is:" << pd << endl;
	return ad;
}

int main()
{
    double a = 3.6;
	double & pa = fn(a);
	cout << pa << endl;
	a = 5.4;
	pa = fn(a);
	cout << pa << endl;
    return 0;
}