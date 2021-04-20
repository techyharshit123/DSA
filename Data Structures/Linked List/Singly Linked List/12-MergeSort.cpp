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

node* midPoint(node *head)
{
	if(head==NULL or head->next==NULL)
		return head;

	node *slow=head;
	node *fast=head->next;

	while(fast and fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;
}
node* mergeSort(node *head)
{
	if(!head or !(head->next))
		return head;

	//1st task  break the linked list by mid point
	node *mid=midPoint(head);
	node *a=head;
	node *b=mid->next;
	mid->next=NULL;

	//2nd task  sort recursively
	a=mergeSort(a);
	b=mergeSort(b);

	//3rd task  merge both the array
	node *c=mergeSorted(a,b);
	return c;
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
	insertAtHead(head,545);
	insertAtHead(head,78);
	insertAtHead(head,93457);
	insertAtHead(head,8927);
	insertAtHead(head,02);
	insertAtHead(head,4989);
	insertAtHead(head,394);
	insertAtHead(head,283);
	printList(head);

	head=mergeSort(head);
	printList(head);
}