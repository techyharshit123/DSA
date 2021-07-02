
//Harshit
 
#include "bits/stdc++.h"
using namespace std;


class node
{
public:
	int data;
	node *next;

	//constructor
	node(int d)
	{
		data=d;
		next=NULL;
	}
};

class Stack{
public:
	node* head=NULL;
	int top=-1;
	int sz=0; //so that we can implement size function in O(1) time and need not do extra work to traverse the Linked list to get the size of the stack.

	void push(int data)
	{
		node *new_node=new node(data);

		new_node->next=head; //we are adding new nodes at head so as to make it O(1) operation
		head=new_node;
		sz++;
	}

	int pop()
	{
		if(head==NULL)
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return 0;
		}

		node *temp=head;
		head=head->next;
		int popped=temp->data;
		delete temp;  //Ensure that no memory leak happens
		sz--;
		return popped;
	}

	int size()
	{
		return sz;
	}

	int peek()
	{
		if(head==NULL)
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return 0;
		}
		return head->data;
	}

	bool isEmpty()
	{
		if(sz==0)
			return true;
		else
			return false;
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
	cout << s.pop() <<endl;
	cout<<s.peek()<<endl;
}
