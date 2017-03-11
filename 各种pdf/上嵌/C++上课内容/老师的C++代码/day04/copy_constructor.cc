#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class Test
{
	char *m_p;
public:
	Test(const char *p)
	{
		m_p = (char *)malloc(sizeof(char)*20);
		strcpy(m_p,p);
	}

	// 深拷贝
	Test(Test &t)
	{
		m_p = (char *)malloc(sizeof(char)*20);	// 申请空间
		strcpy(m_p,t.m_p);										// 赋值
	}



	~Test()
	{
		free(m_p);
	}

	void destroyspace()
	{
			free(m_p);
			return ;
	}

	
	void show()
	{
		cout << " m_p =  " << m_p << endl;	
		return ;
	}
};




int main(int argc,char **argv)
{
	cout << " Test t(\"haha\"); " << endl;
	Test t("haha");
	t.show();

	cout << " Test t1(t); " << endl;
	Test t1(t);


	cout << "t.destroyspace(); " << endl;
	t.destroyspace();

	cout << " t1.show();" << endl;
	t1.show();
	cout << " t.show(); " << endl;
	t.show();

	return 0;
}






