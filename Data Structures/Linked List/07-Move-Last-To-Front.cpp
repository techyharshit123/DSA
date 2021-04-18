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

////////////////////////////////////////*****METHOD-I*****///////////////////////////////////////
void moveLastToFrontI(node*&head)
{
	/* If linked list is empty, or 
    it contains only one node, 
    then nothing needs to be done,
    simply return */
	if(head==NULL or head->next==NULL)
		return;

	node *temp=head;
	node *top=head;
	while(temp->next->next)
	{
		temp=temp->next;
	}
	node *nxt=temp->next;
	temp->next=NULL;
	// nxt=head;
	// head=nxt;
	nxt->next=head;
	head=nxt;
	// head->next=top;
}

////////////////////////////////////////*****METHOD-II*****///////////////////////////////////////
//take 2 pointers
void moveLastToFrontII(node*&head)
{
	/* If linked list is empty, or 
    it contains only one node, 
    then nothing needs to be done,
    simply return */
	if(head==NULL or head->next==NULL)
		return;

	node *secLast = NULL; 
    node *last = head; 
  
    /*After this loop secLast contains
    address of second last node and 
    last contains address of last node in Linked List */
    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
  
    /* Set the next of second last as NULL */
    secLast->next = NULL; 
  
    /* Set next of last as head node */
    last->next = head; 
  
    /* Change the head pointer
    to point to last node now */
    head = last; 
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
	insertAtHead(head,-1);
	insertAtHead(head,-2);
	printList(head);
	// node *now=SwapNodePairwiseIII(head);
	moveLastToFrontII(head);
	printList(head);

}