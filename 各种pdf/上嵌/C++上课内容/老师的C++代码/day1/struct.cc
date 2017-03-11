#include <iostream>
using namespace std;


//struct student
class student//定义了一个student类
{
public://赋予 成员 共有访问权限
		//修饰范围：权限以下的成员，到下一个权限的开始
		//或者到类结束的"}"
	//成员变量
	int age;
	int grade;
	//成员函数：可以直接访问成员变量
	void show()
	{
		cout << "age = " << age << endl;
		cout << "grade = " << grade << endl;
		return;
	}
};




int main(int argc,char **argv)
{
	//struct strdent stu = {12,3};
	//student 是 类（抽象）
	//stu 是 student类的变量------>对象（具体）
	studnet stu = {12,3};
	cout << "age = " << stu.age << endl;
	cout << "grade = " << stu.grade << endl;
	
	stu.show();
	return 0;
}
