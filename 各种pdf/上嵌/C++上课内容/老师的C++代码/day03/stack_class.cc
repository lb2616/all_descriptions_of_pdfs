#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
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

	B b(250.41);
	b.show();

	return 0;
}






