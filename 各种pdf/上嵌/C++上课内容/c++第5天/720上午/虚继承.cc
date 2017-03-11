#include<iostream>
using namespace std;

class Furniture
{
	public:
		Furniture(){}
		void SetWeight(int i){weight = i;}
		int GetWeight(){return weight;}
	protected:
		int weight;
};

class Bed:virtual public Furniture
{
	public:
		Bed(){}
		void Sleep(){cout <<"sleeping ....\n";}
};

class Sofa:virtual public Furniture
{
	public:
		Sofa(){}
		void WatchTV(){cout <<"Watching TV.\n";}
};

class SleeperSofa:public Bed,public Sofa
{
	public:
		SleeperSofa():Sofa(),Bed(){}
		void FoldOut(){cout<<"fold out the sofa.\n";}
};

int main(int argc,char **argv)
{
	SleeperSofa ss;
	ss.SetWeight(20);
	//ss.Bed::SetWeight(20);
	//ss.Bed::Sleep();
	Furniture *pf;
	pf = (Furniture *)&ss;
	cout <<pf->GetWeight()<<endl;
	return 0;
}















