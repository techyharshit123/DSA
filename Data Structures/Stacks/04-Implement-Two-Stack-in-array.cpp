//Harshit
 
#include "bits/stdc++.h"
using namespace std;
///////////////////////////////*************NOT SPACE OPTIMISED***********////////////////////////
class twoStacks
{
public:
	int *arr;
	int size;
	int top1,top2;

	//constructor
	twoStacks(int n)
	{
		size=n;
		arr=new int[n];

		//important
		top1=n/2+1;
		top2=n/2;
	}

	// Method to push an element x to stack1
    void push1(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1 > 0) {
            top1--;
            arr[top1] = x;
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }

    void push2(int x)
    {
 
        // There is at least one empty
        // space for new element
        if (top2 < size - 1) {
            top2++;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow"
                 << " By element :" << x << endl;
            return;
        }
    }
 
    // Method to pop an element from first stack
    int pop1()
    {
        if (top1 <= size / 2) {
            int x = arr[top1];
            top1++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
 
    // Method to pop an element
    // from second stack
    int pop2()
    {
        if (top2 >= size / 2 + 1) {
            int x = arr[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
};
 
/////////////////////////***************SPACE EFFICIENT***************//////////////////////////////
class TwoStacks
{
public:
	int *arr;
	int size;
	int top1,top2;

	TwoStacks(int n)
	{
		size=n;
		top1=-1;
		top2=size;
		arr=new int[n];
	}

	void push1(int data)
	{
		if(top1<top2-1)
		{
			top1++;
			arr[top1]=data;
		}
		else
		{
			cout<<"MEMORY OVERFLOW";
		}
	}

	void push2(int data)
	{
		if(top1<top2-1)
		{
			top2--;
			arr[top2]=data;
		}
		else
		{
			cout<<"MEMORY OVERFLOW";
		}
	}

	int pop1()
	{
		if(top1>=0)
		{
			int popped=arr[top1];
			top1--;
			return popped;
		}
		else
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return INT_MIN;
		}
	}
	int pop2()
	{
		if(top2<size)
		{
			int popped=arr[top2];
			top2++;
			return popped;
		}
		else
		{
			cout<<"MEMORY UNDERFLOW"<<endl;
			return INT_MIN;
		}
	}
};
/* Driver program to test twStacks class */
int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    return 0;
}
