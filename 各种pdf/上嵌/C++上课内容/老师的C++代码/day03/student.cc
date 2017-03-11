#include <iostream>
using namespace std;

/**
* 学生类
**/
class Student
{
	string m_name;		// 学生姓名
	static string m_tname;	// 老师姓名
	static string m_course;	// 课程名称
public :
	Student(string name):m_name(name){}
	~Student(){}

	// 上课
	void listen()
	{
		cout << m_name << " 在听 " 
			<< m_tname << " 讲 " 
			<< m_course << " 课程！" << endl;
	}

	// 更换老师和课程
	// 静态成员函数
	static void change(string name,string course)
	{
		m_tname = name;
		m_course = course;

		// 静态成员函数中 只能 使用静态成员变量
		//cout << m_name << " 更换 ";
		cout << " 更换 "
			<< m_tname << " 讲 " 
			<< m_course << " 课程！！！"
			<< endl;
		return ;
	}
};

string Student::m_tname = "马老师";
string Student::m_course = "C++";


int main(int argc,char **argv)
{
	Student s1("小明");
	Student s2("小王");

	s1.listen();
	s2.listen();

	// 不符号真实情况，明明只有小明换了老师，
	// 为什么  小王的老师也换了
	Student::change("朱老师","Qt");

	s1.listen();
	s2.listen();

	return 0;
}




