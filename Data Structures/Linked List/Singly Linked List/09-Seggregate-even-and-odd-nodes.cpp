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
node* divide(node *head){
        // code here
        node*es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
        
        node *curr=head;
        while(curr)
        {
            if(curr->data & 1)
            {
                if(os)
                {
                    oe->next=curr;
                    oe=oe->next;
                }
                else
                {
                    os=curr;
                    oe=os;
                }
            }
            else
            {
                if(es)
                {
                    ee->next=curr;
                    ee=ee->next;
                }
                else
                {
                    es=curr;
                    ee=es;
                }
            }
            curr=curr->next;
        }
        
        if(ee==NULL or oe==NULL)
        {
            return head;
        }
        
        ee->next=os;
        oe->next=NULL;
        
        return es;
    }

////////////////////////////////**********METHOD-II************///////////////////////////////
void segregateEvenOdd(node *&head) 
{ 
    node *end = head; 
    node *prev = NULL; 
    node *curr = head; 
  
    /* Get pointer to the last node */
    while (end->next != NULL) 
        end = end->next; 
  
    node *new_end = end; 
  
    /* Consider all odd nodes before the first 
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end) 
    { 
        new_end->next = curr; 
        curr = curr->next; 
        new_end->next->next = NULL; 
        new_end = new_end->next; 
    } 
  
    // 10->8->17->17->15 
    /* Do following steps only if 
    there is any even node */
    if (curr->data%2 == 0) 
    { 
        /* Change the head pointer to 
        point to first even node */
        head = curr; 
  
        /* now current points to
        the first even node */
        while (curr != end) 
        { 
            if ( (curr->data) % 2 == 0 ) 
            { 
                prev = curr; 
                curr = curr->next; 
            } 
            else
            { 
                /* break the link between
                prev and current */
                prev->next = curr->next; 
  
                /* Make next of curr as NULL */
                curr->next = NULL; 
  
                /* Move curr to end */
                new_end->next = curr; 
  
                /* make curr as new end of list */
                new_end = curr; 
  
                /* Update current pointer to
                next of the moved node */
                curr = prev->next; 
            } 
        } 
    } 
  
    /* We must have prev set before executing 
    lines following this statement */
    else prev = curr; 
  
    /* If there are more than 1 odd nodes 
    and end of original list is odd then 
    move this node to end to maintain 
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0) 
    { 
        prev->next = end->next; 
        end->next = NULL; 
        new_end->next = end; 
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
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,1);
	printList(head);

	// node *ans=divide(head);

	segregateEvenOdd(head);

	printList(head);
	
}