//Harshit
 
#include "bits/stdc++.h"
using namespace std;

class Stack{
public:
	std::vector<int> v;

	void push(int x)
	{
		v.push_back(x);
	}

	int pop()
	{
		if(v.empty())
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return 0;
		}
		int res=v.back();
		v.pop_back();
		return res;
	}

	int peek()
	{
		if(v.empty())
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return 0;
		}
		int res=v.back();
		return res;
	}

	int size()
	{
		return v.size();
	}

	bool isEmpty()
	{
		return v.empty();
	}
};

int main()
{
	Stack s;

	cout<<s.pop()<<endl;
	cout<<s.peek()<<endl;
	s.push(10);
	s.push(100);
	s.push(1000);
	s.push(10000);
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
}
