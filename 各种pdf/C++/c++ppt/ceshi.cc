#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		Student(char *pName = "no name",int ssid = 0)
		{
			strncpy(name,pName,40);
			name[39]='\0';
			id = ssid;
			cout <<"constructing new student " <<pName<<endl;
		}
		Student(Student &s)
		{
			cout <<"constructing copy of "<<s.name<<endl;
			strcpy(name,"copy of ");
			strcat(name,s.name);
			id = s.id;
		}
		~Student()
		{
			cout <<"Destructing " << name <<endl;
		}
		protected:
			char name[40];
			int id;
};

void fn(Student s)
{
	cout <<"In function fn()\n";
}

int main()
{
	Student randy("Randy",1234);
	cout <<"Calling fn()\n";
	fn(randy);
	cout <<"Returned from fn()\n";
	return 0;
}










