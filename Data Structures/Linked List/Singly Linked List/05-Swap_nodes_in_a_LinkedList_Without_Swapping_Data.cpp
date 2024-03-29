//Harshit
// In this problem simply swap two nodes
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
void swapNodesI(node *&head, int x,int y)
{
	if(x==y)
		return;

	//search for x
	node *prevx=NULL,*currx=head;
	while(currx)
	{
		if(currx->data==x)
			break;
		prevx=currx;
		currx=currx->next;
	}

	//search for y
	node *prevy=NULL,*curry=head;
	while(curry)
	{
		if(curry->data==y)
			break;
		prevy=curry;
		curry=curry->next;
	}

	if(curry==NULL or currx==NULL)
		return;

	// If x is not head of linked list
    if (prevx != NULL)
        prevx->next=curry;
    else // Else make y as new head
        head=curry;
 
    // If y is not head of linked list
    if (prevy != NULL)
    	prevy->next=currx;
    else // Else make x as new head
    	head=currx;

    //swap the next pointer of both the node
    node* temp = curry->next;
    curry->next = currx->next;
    currx->next = temp;
	return;
}

////////////////////////////////////////*****METHOD-II*****///////////////////////////////////////
//Optimized code ----->  search x and y in single traversal
void swapNodesII(node *&head, int x,int y)
{
	if(x==y)
		return;

	//search for x
	node *a = NULL, *b = NULL;
 
    // search for x and y in the linked list
    // and store therir pointer in a and b
    while (head) {
 
        if ((head)->data == x) {
            a = head;
        }
 
        else if ((head)->data == y) {
            b = head;
        }
 
        head = ((head)->next);
    }
 
    // if we have found both a and b
    // in the linked list swap current
    // pointer and next pointer of these
    if (a && b) {
 
        swap(*a, *b);
        swap(((a)->next), ((b)->next));
    }
	return;
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
	insertAtHead(head,20);
	insertAtHead(head,11);
	insertAtHead(head,45);
	insertAtHead(head,8);
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	printList(head);

	swapNodesI(head,11,5);

	printList(head);

	
}