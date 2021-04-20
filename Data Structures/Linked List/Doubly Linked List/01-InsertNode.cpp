//Harshit
 
#include "bits/stdc++.h"
using namespace std;

class node
{
public:
	int data;
	node *prev;
	node *next;
	node(int d)
	{
		data=d;
		prev=next=NULL;
	}
};

void insertAtBegin(node* &head,int data)
{
	node *n=new node(data);

	n->next=head;

	if(head)
	{
		head->prev=n;
	}
	head=n;
	return;
}

void insertAtEnd(node *&head,int data)
{
	node* n=new node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}

	node *temp=head;
	while(temp->next)
	{
		temp=temp->next;
	}
	//link both nodes to each other
	n->prev=temp;
	temp->next=n;
	return;
}

void printList(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	node *head=NULL;
	insertAtEnd(head,78);
	insertAtEnd(head,7845);
	insertAtEnd(head,7825);
	insertAtBegin(head,78123);
	printList(head);
}
