#include<iostream>
using namespace std;

class Student
{
public:
	static int noofstudents;
	int temp;
	Student(){temp = 100;}
	static void addstudent()
	{
		noofstudents++;
		//temp--;
	}
};

int Student::noofstudents = 0;
int main()
{
	Student ss;
	Student::addstudent();
	Student::addstudent();
	cout<<Student::noofstudents<<endl;
}
