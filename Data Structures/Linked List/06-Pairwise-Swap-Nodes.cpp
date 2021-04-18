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
//SWAPPING DATA ----> not a good idea as data may be large also 

//Recursive
void SwapNodePairwiseI(node *head)
{
	if (head != NULL && head->next != NULL) {
  
        /* Swap the node's data with data of next node */
        swap(head->data, head->next->data);
  
        /* Call pairWiseSwap() for rest of the list */
        SwapNodePairwiseI(head->next->next);
    }
}

////////////////////////////////////////*****METHOD-II*****///////////////////////////////////////

//Pairwise swap elements of a given linked list by changing links
node* SwapNodePairwiseII(node *head)
{
	if(head==NULL or head->next==NULL)
		return head;

	node *curr=head->next->next;

	//take care of first 2 nodes separately
	node *prev=head;
	head=head->next;
	head->next=prev;

	while(curr and curr->next)   //suppose case of 3 nodes and there curr->next will be invalid and can't be part of swap
	{
		node *temp=curr;

		prev->next=curr->next;	
		curr->next=prev->next->next;
		prev->next->next=temp;
		//now moving curr and prev further to swap further elements
		curr=curr->next;
		prev=prev->next->next;
	}
	prev->next=curr;
	return head;

}

////////////////////////////////////////*****METHOD-III*****///////////////////////////////////////

//Pairwise swap elements of a given linked list by changing links
node* SwapNodePairwiseIII(node *head)
{
	if(head==NULL or head->next==NULL)
		return head;

	node *curr=head->next->next;

	//take care of first 2 nodes separately
	node *prev=head;
	head=head->next;
	head->next=prev;

	while(curr and curr->next)   //suppose case of 3 nodes and there curr->next will be invalid and can't be part of swap
	{
		prev->next=curr->next;
		prev=curr;

		//capturing the next node to hold the reference of further linked list
		node *next=curr->next->next;

		curr->next->next=prev;
		curr=next;
	}
	prev->next=curr;
	return head;

}

////////////////////////////////////////*****METHOD-IV*****///////////////////////////////////////
//recursive solution
node* pairWiseSwap(node* head)
{
    // Base Case: The list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;
 
    // Store head of list after two nodes
    node* remaing = head->next->next;
 
    // Change head
    node* newhead = head->next;
 
    // Change next of second node
    head->next->next = head;
 
    // Recur for remaining list and change next of head
    head->next = pairWiseSwap(remaing);
 
    // Return new head of modified list
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
	insertAtHead(head,0);
	insertAtHead(head,-1);
	insertAtHead(head,-2);
	printList(head);
	node *now=pairWiseSwap(head);
	printList(now);

}