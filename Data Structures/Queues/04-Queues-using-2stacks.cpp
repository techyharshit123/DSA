//Harshit
 
#include "bits/stdc++.h"
using namespace std;


class Queue
{
public:
	stack<int>s1,s2;

	void push(int x)
	{
		s1.push(x);
	}
	void pop()
	{
		if(s1.empty())
			return;
		while(s1.size()>1)
		{
			s2.push(s1.top());
			s1.pop();
		}

		s1.pop();
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

};
int main()
{

}
