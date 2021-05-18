//Harshit
 
#include "bits/stdc++.h"
using namespace std;
typedef uintptr_t ut;

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
void insertAtHead(node *&head,int d)
{
	if(head==NULL)
	{
		// int d;
		head=new node(d);
		return;
	}

	//create new node
	node *n = new node(d);
	n->next=head;
	head=n;
}

////////////////////////////////////////*****USING ITERATION*****///////////////////////////////////////
// using 3 pointer
node* reverseList(node *head)
{
	node *prev=NULL;
    node *curr=head;
    
    while(curr->next)
    {
        node *rem=curr->next;
        curr->next=prev;
        prev=curr;
        curr=rem;
    }
    curr->next=prev;
    return curr;
}

//using 2 pointers
//The idea is to use XOR to swap pointers. 
node* reverseLL(node* head)
{
	node* prev=NULL;
	node* curr=head;

	while(curr!=NULL)
	{
		curr = (node*)((ut)prev ^ (ut)curr ^ (ut)(curr->next) ^ (ut)(curr->next = prev) ^ (ut)(prev = curr));
	}

	head=prev;
	return head;
}

////////////////////////////////////////*****USING Recursion*****///////////////////////////////////////
//METHOD-I
node* reverseListRecurrI(node *head)
{
	if(head->next==NULL)
    return head;
    
    node *rest_head=reverseListRecurrI(head->next);
    
    node *rest_tail=head->next;
    
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

//METHOD-II

node* reversefun(node *curr,node *prev)
{
	if(curr==NULL)
		return prev;

	node *next=curr->next;
	curr->next=prev;
	return reversefun(next,curr);
}
node* reverseListRecurrII(node *head)
{
	if(head->next==NULL)
    return head;
    
    node *newhead=reversefun(head,NULL);
    return newhead;
}

void printList(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}

	cout<<endl;
}
int main()
{
	node *head=NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,1);
	printList(head);

	node *ans=reverseLL(head);
	printList(ans);
}