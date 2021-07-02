//Harshit
 
#include "bits/stdc++.h"
using namespace std;

// METHOD-1 (making push operation costly)

// METHOD-2 (making pop operation costly)
class Stack
{
public:
	queue<int>q1;
	queue<int>q2;

	void push(int x)
	{
		q1.push(x);
	}
	void pop()
	{
		//remove the last added items from q1
		//move first n-1 element to q2
	 	//interchange the name of q1 and q2
		if(q1.empty())
			return;

		while(q1.size()>1)
		{
			int x=q1.front();
			q1.pop();
			q2.push(x);
		}
		q1.pop(); //to pop the last element from q1 
		queue<int>q=q1;
		q1=q2;
		q2=q;
	}
	int top()
	{
		return q1.back();
	}
	bool empty()
	{
		return q1.size()==0;
	}

};
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
