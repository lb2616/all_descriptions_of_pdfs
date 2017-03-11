#include <iostream>
using namespace std;

/**
* 女孩类
**/
class Girl		// 类名 首字母大写
{
// 类中的成员默认的访问权限是  private
//  结构体  默认的访问权限  是  public
//private:	//  私有访问修饰符  ---
		 //		它修饰的 成员 只能通过 成员函数访问	
		//		在类的外部是无法访问的
		//		一般比较私密或者重要的变量，我们一
		//		般用 private修饰
	int m_age;	// 成员变量的命名规范 m_ 开头

public:	//  公有访问修饰符  ---
		 //		它 修饰的 成员 在 任何地方都可以访问

	void setAge(int age)
	{
		cout << " setAge(int age) " << endl;
		m_age = age;
		return ;
	}

	int getAge()
	{
		return m_age;
	}


};



int main(int argc,char **argv)
{
	Girl g;
	g.setAge(19);
	cout << " g.m_age = " << g.m_age << endl;

	return 0;
}






