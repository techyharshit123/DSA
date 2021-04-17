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

void deleteAtHead(node *&head)
{
	if(head==NULL)
		return ;

	node *temp=head->next;
	delete(head);
	head=temp;
}

void deleteAtTail(node *&head)
{
	if(head==NULL)
		return;

	node *temp=NULL;
	node *curr=head;

	while(curr->next)
	{
		temp=curr;
		curr=curr->next;
	}

	temp->next=NULL;
	delete(curr);

}

void deleteAtMiddle(node *&head, int pos)
{
	int cnt=0;
	if(head==NULL)
		return;

	if(pos==0)
		deleteAtHead(head);

	node *curr=head;
	node *temp=NULL;

	while(cnt!=(pos-1))
	{
		temp=curr;
		curr=curr->next;
		cnt++;
	}
	if(curr==NULL)
		return;
	temp->next=curr->next;
	delete(curr);

}

void deleteList(node *&head)
{
	node *curr=head;

	while(curr)
	{
		node *temp=curr->next;
		delete(curr);
		curr=temp;
	}

	head=NULL;
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
	// insertAtHead(head,2);
	// insertAtHead(head,1);
	// insertAtHead(head,1);
	// printList(head);

	// deleteAtMiddle(head,2);

	// printList(head);
	// deleteList(head);
	printList(head);
}