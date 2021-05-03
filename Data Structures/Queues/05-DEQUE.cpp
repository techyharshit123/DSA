//Harshit
 
#include "bits/stdc++.h"
using namespace std;


class DEQUE
{
public:
	int* a;
	int front;
	int size;
	int capacity;

	DEQUE(int c)
	{
		a= new int[c];
		capacity=c;
		size=0;
		front=0;		
	}
	bool isFull()
	{
		return size==capacity;
	}
	bool isEmpty()
	{
		return size==0;
	}
	int getRearIndex()
	{
		if(size==0)
			return -1;
		else
			return (front+size-1)%capacity;
	}

	void insertAtFront(int x)
	{
		if(isFull())
		{
			cout<<"MEMORY OVERFLOW"<<endl;
			return;
		}
		cout<<front<<" ";
		front=(front-1+capacity)%capacity;
		a[front]=x;
		size++;
	}
	void insertAtRear(int x)
	{
		if(isFull())
		{
			cout<<"MEMORY OVERFLOW"<<endl;
			return;
		}

		int rear=getRearIndex();
		rear=(rear+1)%capacity;
		cout<<rear<<" ";
		a[rear]=x;
		size++;
	}
	void deleteAtFront()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return;
		}

		front=(front+1)%capacity;
		size--;
	}
	void deleteAtRear()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return;
		}
		int rear=getRearIndex();
		// rear=(rear-1+capacity)%capacity;  //we don't need this as we are not maintaining any rear so no point of changing it as it will automatically get updated as size variable is changing
		size--;
	}
	int getFront()
	{
		if(isEmpty())
			return -1;
		else
		{
			// cout<<front<<" ";
			return a[front];
		}
	}
	void display()
	{
		while(size!=0)
		{
			cout<<getFront()<<endl;
			deleteAtFront();
		}
	}
};
int main()
{
	DEQUE dq(4);

	dq.insertAtRear(3);
	cout<<dq.getFront()<<endl;

	dq.insertAtFront(4);
	cout<<dq.getFront()<<endl;

	dq.insertAtRear(5);
	cout<<dq.getFront()<<endl;

	dq.insertAtFront(6);
	cout<<dq.getFront()<<endl;


	dq.display();
}
