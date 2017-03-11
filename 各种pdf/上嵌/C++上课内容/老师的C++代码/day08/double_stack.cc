#include <iostream>
#include <stack>
using namespace std;
/*
front()	返回队头元素                  -------------
back()	返回队尾元素		     -------------
push()	入队				          入栈
pop()	出队				          出栈
empty()    判断容器中的元素是否为空  empty
size()	返回容器中元素的大小          size
*/
stack<int> s1;		// 存放元素
stack<int> s2;		// 辅助

// 返回队头元素
int front()
{
	while(s1.size())
	{
		int tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	}

	int head = s2.top();

	while(s2.size())
	{
		int tmp = s2.top();
		s2.pop();
		s1.push(tmp);
	}

	return head;
}

//返回队尾元素
int back()
{
	return s1.top();
}

// 入队	
void push(int data)
{
	s1.push(data);
	return ;
}

// 出队	
void pop()	
{
	while(s1.size())
	{
		int tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	}

	s2.pop();

	while(s2.size())
	{
		int tmp = s2.top();
		s2.pop();
		s1.push(tmp);
	}
	
	return ;
}

// 判断容器中的元素是否为空
bool empty()
{
	return s1.empty();
}

// 返回容器中元素的大小  
int size()
{
	return s1.size();
}

int main(int argc,char**argv)
{
	cout << " empty() = " << empty() << endl;
	cout << " size = " << size() << endl;

	push(10);
	push(20);
	push(30);

	cout << " front() = " << front() << endl;
	cout << " back() = " << back() << endl;

	pop();

	cout << " front() = " << front() << endl;
	cout << " back() = " << back() << endl;

	pop();
	pop();

	cout << " empty() = " << empty() << endl;
	cout << " size = " << size() << endl;


	return 0;
}
