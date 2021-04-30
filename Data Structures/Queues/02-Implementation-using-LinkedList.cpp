//Harshit
 
#include "bits/stdc++.h"
using namespace std;


class Node
{
public:
	int data;
	Node* next;

	Node(int d)
	{
		data=d;
		next=NULL;
	}
};

class Queue
{
public:
	Node* front=NULL;
	Node* rear=NULL;
	int curr_size=0;

	void enque(int x)
	{
		Node* new_node=new Node(x);
		if(front==NULL)	   //In case of addition of first node we'll be need to change the front too but otherwise front is not changed only rare does
		{
			front=new_node;
			rear=front;
			curr_size++;
			return;
		}

		rear->next=new_node;
		rear=new_node;
		curr_size++;
	}
	void deque()
	{
		if(front==NULL)
		{
			cout<<"MEMORY UNDERFLOW";
			return;
		}

		Node* temp=front;
		front=front->next;
		delete(temp);
		if(front==NULL)  //in case of deletion of last node we'll change the rear also to NULL otherwise the rear remains unchanged
			rear=NULL;
	}
	int getFront()
	{
		if(front==NULL)
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		return front->data;
	}
	int getRear()
	{
		if(rear==NULL)
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		return rear->data;
	}

	void display()
	{
		Node *temp=front;
		while(temp)
		{
			cout<<temp->data<<"-> ";
			temp=temp->next;
		}
		cout<<endl;
	}
};


int main()
{
	Queue q;
    q.enque(10);
    q.display();
    q.enque(20);
    q.display();
    q.enque(30);
    q.display();
    // q.enque(8);
    // q.enque(7);
    // q.enque(8);//show memory overflow 
    q.deque();
    q.deque();
    q.display();
    q.deque();
    q.display();
    q.deque();
    q.display();
    q.enque(40);
    q.display();
    q.enque(50);
    q.display();
    q.enque(60);
    q.display();
    q.enque(70);
    q.display();
    q.deque();
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;


}
