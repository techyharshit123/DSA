//Harshit
 
#include "bits/stdc++.h"
using namespace std;

///////////////*********METHOD-1***********/////////////////////
// TC=O(n)
// SC=O(n) //for auxillary stack
 // Here we will use another auxillary stack 

///////////////*********METHOD-2***********/////////////////////
// TC=O(n)
// SC=O(n)  //for function call stack
void ReverseQueue(queue<int>&q)
{
	if(q.empty())
		return;

	int data=q.front();
	q.pop();

	ReverseQueue(q);

	q.push(data);
}

void display(queue<int>q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
int main()
{
	queue<int>q;
	q.push(4);
	q.push(3);
	q.push(2);
	q.push(1);
	display(q);
	ReverseQueue(q);
	display(q);
}