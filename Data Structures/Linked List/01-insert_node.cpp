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
		head=new node(d);
		return;
	}

	//create new node
	node *n = new node(d);
	n->next=head;
	head=n;
}
void insertAtTail(node *&head,int d)
{
	node *n=head;
	// n->next=NULL;

	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	// node *temp=head;
	// node *curr=head;
	// while(temp!=NULL)
	// {
	// 	curr=curr->next;
	// 	if(curr!=NULL)
	// 	temp=temp->next;
	// 	else
	// 		break;
	// }

	// or

	while(n->next!=NULL) {
	    n=n->next;
	}

	n->next=new node(d);

}

int length(node *head)
{
	int cnt=0;
	while(head!=NULL)
	{
		cnt++;
		head=head->next;
	}

	return cnt;
}
int cnt=0;
void insertInMiddle(node *&head,int d,int p)
{
	if(head==NULL or p==0)
	{
		insertAtHead(head,d);
	}
	else if(p>length(head))
	{
		insertAtTail(head,d);
	}
	node *temp=head;
	// temp->data=head->data;
	// temp->next=head->next;
	// node *req;

	while(cnt!=(p-1)){
		cnt++;
		temp=temp->next;
	}
	node *n=new node(d);   //create new node
	n->next=temp->next;   //new node will contain reference to next node
	temp->next=n;   //now temp will point to new node

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
	insertAtHead(head,0);
	insertAtTail(head,-1);
	insertAtTail(head,-10);
	insertAtHead(head,20);
	insertInMiddle(head,1000000,3);

	printList(head);
}