#include<iostream>
using namespace std;

class Test
{
	int m_data;
	public:
		Test(int data = 10):m_data(data){}
		~Test(){}
		
		/*
		void show()
		{
			//2.const 也能构成函数重载 (特例)
			cout << "show()" <<endl;
			return ;
		}
		*/
		//常成员函数
		void show()const
		{
			//不能修改 成员变量的值
			//error
			//cout <<" m_data= " << ++m_data <<endl;//常成员函数不能些该成员变量的值
			cout << "show()const "<< endl;
			cout << "m_data =" <<m_data <<endl;
			
			return ;
		}
};

int main(int argc,char **argv)
{
	Test t;
	//调用方式和普通成员函数一样
	//普通对象 优先调用  普通的成员函数
	// 常对象 只能调用  常成员函数
	t.show();
	cout << "const Test t1: "<<endl;
	const Test t1;
	t1.show();
	return 0;
	

}


