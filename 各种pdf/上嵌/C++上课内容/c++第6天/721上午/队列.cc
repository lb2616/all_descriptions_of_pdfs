#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	stack<int> st;//堆
	queue<int> q;//队列
	st.push(10);
	st.push(20);
	q.push(30); //queue 和 stack 都有push 操作
	q.push(40);
	cout <<st.top() <<endl;
	st.pop();
	cout <<st.top()<<endl;
	cout <<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	while(!st.empty())
	{
		int a = st.top();
		cout <<a<<endl;
		st.pop();
	}
	return 0;
}

