#include <iostream>
using namespace std;

class A
{
public:

	class B
	{
		double m_data;
	public :
		B(double data):m_data(data)
		{
			cout << " Test() " << endl;
		}
	
		~B()
		{
			cout << " ~Test()" << endl;
		}


		void show()
		{
			cout << " m_data = " << m_data
				<< endl;
		}

	};
	
};

int main(int argc,char **argv)
{
	A::B b(250.41);
	b.show();


	return 0;
}






