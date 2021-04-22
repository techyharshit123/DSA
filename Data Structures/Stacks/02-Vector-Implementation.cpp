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
		if(top==-1)
		{
			cout<<"MEMORY UNDERFLOW";
			return 0;
		}

		int res=v.back();
		v.pop_back();
		top--;
		return res;
	}

	int peek()
	{
		if(top==-1)
		{
			cout<<"MEMORY UNDERFLOW";
			return 0;
		}

		int res=v.back();
		return res;
	}

	int size()
	{
		return (top+1);
	}

	bool isEmpty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
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
	s.push(10000); //at this stage we'll get MEMORY OVERFLOW in output
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
}
