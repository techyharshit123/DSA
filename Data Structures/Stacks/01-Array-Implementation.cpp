//Harshit
 
#include "bits/stdc++.h"
using namespace std;

class Stack{
public:
	int *arr;
	int sz;
	int top;

	Stack(int s)
	{
		sz=s;
		arr=new int[sz]; //creating a dynamic array
		top=-1;
	}

	void push(int x)
	{
		if(top==(sz-1))
		{
			cout<<"MEMORY OVERFLOW";
			return;
		}

		top++;
		arr[top]=x;
	}

	int pop()
	{
		if(top==-1)
		{
			cout<<"MEMORY UNDERFLOW";
			return 0;
		}

		int res=arr[top];
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

		int res=arr[top];
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
	Stack s(3);

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
