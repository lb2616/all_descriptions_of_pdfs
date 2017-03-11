 #include<iostream>
 using namespace std;
class Base
{
public:
	int m1;
protected:
	int m2;
private:
	int m3;
	};
class PrivateClass:private Base //私有继承
{
public:
void test()
{
m1=1; //ok：将m1据为private
m2=2; //ok：将m2据为private
//m3=3; //不可访问
}
};

class PublicClass:public Base
{
	public:
	void test()
	{
		m1 = 1;
		m2 = 2;
		//m3 = 3;
	}
};

class DerivedFromPri:public PrivateClass
{
public:
void test()
{
//m1=1;//不可访问基类的私有成员
//m2=2;//不可访问
//m3=3;//不可访问
}
};
class ProtectdedClass:protected Base //保护继承
{
	public:
		void test()
		{
			m1 = 1;
			m2 = 2;
		//	m3 = 3;
		}
};

class DerivedFromPro:public ProtectedClass
{
	public:
		void test()
		{
			m1 = 1;
			m2 = 2;
			//m3 = 3 // 不可访问
		}
};

int main()
{
	PrivateClass priobj;
//	priobj.m1 = 1;//error
//	priobj.m2 = 2;//error
//	priobj.m3 = 3;//error
	
	ProtectdedClass proobj;
//	proobj.m1 = 1;//error
	//proobj.m2 = 2;//error
	//proobj.m3 = 3;//error
	/*
	publicClass pubobj;
	pubobj.m1 = 1;//error
	pubobj.m2 = 2;//error
	pubobj.m3 = 3;//error
	*/
	return 0;
}









