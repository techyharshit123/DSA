// //Harshit
 
#include "bits/stdc++.h"
using namespace std;

///////////////////////////////***************SIMPLE IMPLEMENTATION*************///////////////////////////
//deque takes O(n) time
class Queue
{
public:
	int *a;
	int curr_size;
	int capacity;

	Queue(int n)
	{
		capacity=n;
		curr_size=0;
		a=new int[capacity];
	}

	bool isFull()
	{
		return curr_size==capacity;
	}
	bool isEmpty()
	{
		return curr_size==0;
	}
	void enque(int x)
	{
		if(curr_size==capacity)
		{
			cout<<"MEMORY OVERFLOW";
			return;
		}
		a[curr_size]=x;
		curr_size++;
	}
	void deque()
	{
		if(curr_size==0)
		{
			cout<<"MEMORY UNDERFLOW";
			return;
		}

		//remove element from starting 
		for(int i=0;i<curr_size-1;i++)
			a[i]=a[i+1];
		curr_size-1;
	}
	int getFront()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		else
		{
			return a[0]; 
		}
	}
	int getRear()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		else
		{
			return a[curr_size-1]; 
		}
	}
};



///////////////////////////////***************EFFICIENT IMPLEMENTATION*************///////////////////////////
											//////CIRCULAR ARRAY/////
//deque takes O(1) time for all operation
//Do not waste space in the array memory, if space is present in array then the item will bw inserted into the queue
class Queue
{
public:
	int *a;
	int capacity;
	int curr_size;
	int front;
	// int rear;     //not need to maintain rear because it can always be found as (front+curr_size-1)%capacity;

	Queue(int n)
	{
		capacity=n;
		curr_size=0;
		front=0;
		a=new int[capacity];
	}
	bool isFull()
	{
		return curr_size==capacity;
	}
	bool isEmpty()
	{
		return curr_size==0;
	}
	int getRearIndex()
	{
		if(curr_size==0)
			return -1;
		else
			return (front+curr_size-1)%capacity;
	}
	void enque(int x)
	{
		if(isFull())
		{
			cout<<"MEMORY OVERFLOW";
			return;
		}		
		int rear=getRearIndex();
		rear=(rear+1)%capacity;
		a[rear]=x;
		curr_size++;
	}
	void deque()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW";
			return;
		}
		front=(front+1)%capacity;
		curr_size--;
	}
	int getFront()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		else
		{
			return a[front]; 
		}
	}
	int getRear()
	{
		if(isEmpty())
		{
			cout<<"MEMORY UNDERFLOW";
			return INT_MIN;
		}
		else
		{
			return a[getRearIndex()]; 
		}
	}
};
int main()
{
	int n;
	cout << "Enter the maximum size of queue : ";
    cin >> n;
    Queue q(n);

    q.enque(10);
    q.enque(20);
    q.enque(30);
    // q.enque(8);
    // q.enque(7);
    // q.enque(8);//show memory overflow 
    q.deque();
    q.deque();
    q.enque(40);
    q.enque(50);
    q.enque(60);
    q.enque(70);
    q.deque();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;


}
