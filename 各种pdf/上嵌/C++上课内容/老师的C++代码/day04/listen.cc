#include <iostream>
using namespace std;

/**
* 教师类
**/
class Teacher
{
	string m_name;		// 姓名
	string m_course;		// 课程
	string m_addr;		// 地点
public:
	// 参数列表的顺序 和  初始化列表顺序没关系
	//							只和  参数传递的顺序有关系
	Teacher(string name,string addr,string course):
		m_name(name),
		m_course(course),
		m_addr(addr){}
	~Teacher(){}

	string getCourse(){ return m_course;}
	string getAddr(){ return m_addr;}


	void teach();
};

void Teacher::teach()
{
	cout << m_name << "  在 "
			<< m_addr << " 教 "
			<< m_course << " 课程" << endl;
	return ;
}

/**
* 学生类
**/
class Student
{
	string m_name;		// 姓名
public:
	Student(string name):m_name(name){}
	~Student(){}

	void listen(string szTime,Teacher &);
};

void Student::listen(string szTime,Teacher &t)
{
	//小甜甜 上午 在 项目一组 上 C++课程

	cout << m_name << " "
			<< szTime <<  "  在 "
			<< t.getAddr() << " 上 "
			<<  t.getCourse() << " 课程" << endl;
	return ;
}

int main(int argc,char **argv)
{
	Teacher t1("马老师","项目一组","C++");
	Teacher t2("江老师","项目四组","Arm");
	Student s("小天天");

	t1.teach();
	t2.teach();
	
	s.listen("上午",t1);
	s.listen("下午",t2);

	return 0;
}
