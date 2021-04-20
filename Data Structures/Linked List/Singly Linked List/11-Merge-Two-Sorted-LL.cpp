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
node* mergeSorted(node *a,node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	node *head=NULL,*tail=NULL;

	if(a->data<=b->data)
	{
		head=tail=a;
		a=a->next;
	}
	else
	{
		head=tail=b;
		b=b->next;
	}

	while(a and b)
	{
		if(a->data<=b->data)
		{
			tail->next=a;
			tail=a;
			a=a->next;
		}
		else
		{
			tail->next=b;
			tail=b;
			b=b->next;
		}
	}

	if(!a)
		tail->next=b;
	else
		tail->next=a;

	return head;
}


////////////////////////////////////////*****USING Recursion*****///////////////////////////////////////
node* sortedMergeRecur(node* head1, node* head2)  
{  
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    // Node *head=NULL,*tail=NULL;
    
    if(head1->data<=head2->data)
    {
        head1->next=sortedMergeRecur(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=sortedMergeRecur(head1,head2->next);
        return head2;
    }
    // code here
}


//TC=O(n)  and  SC=O(1)
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
	node *a=NULL;
	insertAtHead(a,30);
	insertAtHead(a,20);
	insertAtHead(a,1);
	insertAtHead(a,1);
	printList(a);

	node *b=NULL;
	insertAtHead(b,300);
	insertAtHead(b,200);
	insertAtHead(b,10);
	insertAtHead(b,10);
	printList(b);

	node *head=sortedMergeRecur(a,b);
	printList(head);


}