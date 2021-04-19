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
	prev=curr;
	curr=next;
	return reversefun(curr,prev);
	// prev=curr;
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

	node *ans=reverseListRecurrII(head);
	printList(ans);
}