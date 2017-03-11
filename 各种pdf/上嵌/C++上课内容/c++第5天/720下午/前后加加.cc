
#include<iostream>
using namespace std;

class RMB
{
	public:
		RMB(unsigned int d,unsigned int c){ yuan = d,jf = c;}
		//friend RMB operator + (const RMB&,const RMB&);
	//	friend RMB& operator ++(RMB&);
		void display(){ cout<<(yuan+jf/100.0)<<endl;}
	protected:
		unsigned int yuan;
		unsigned int jf;
};

RMB operator + (const RMB& s1,const RMB& s2)
{
	unsigned int jf = s1.jf + s2.jf;
	unsigned int yuan = s1.yuan + s2.yuan;
	RMB result(yuan,jf);
	return result;
}



RMB operator ++(int)
{
	RMB temp(*this);//临时对象存放原有对象值
	jf++;
	if(jf>=100)
	{
		jf = 100;
		jf-=100;
		yuan++;
	}
	return temp;//返回原有对象值
}
/*
RMB& operator ++(RMB& s)
{
	s.jf++;
	if(s.jf>=100)
	{
		s.jf -= 100;
		s.yuan++;
	}
	return s;
}
*/
int main(int argc,char **argv)
{
	RMB a(100,1),b(1,2),c(0,0);
	c = a+b;
	//c.display();
	c++.display();
	//++c;
	c.display();
	return 0;
}







