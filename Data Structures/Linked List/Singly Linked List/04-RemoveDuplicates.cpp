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
node* RemoveDuplicatesI(node *head)
{
	node *current=head;

	/* Pointer to store the next pointer of a node to be deleted*/
    node* nxt;

    while(current->next!=NULL)
    {
    	if(current->data==current->next->data)
    	{
    		nxt=current->next->next;
    		delete(current->next);
    		current->next=nxt;
    	}
    	else
    	{
    		current=current->next;
    	}
    }

    return head;
}

////////////////////////////////////////*****METHOD-II*****///////////////////////////////////////
node* RemoveDuplicatesII(node *head)
{
	node* prev=head;
    node* temp=head->next;
    
    while(temp)
    {
        if(prev->data==temp->data)
        {
            temp=temp->next;
        }
        else
        {
            prev->next=temp;
            prev=prev->next;
            temp=temp->next;
        }
    }
     /*This is the edge case if there
	  are more than one occurrences
	  of the last element*/
	  if(prev != temp)
	  {
	        prev->next = NULL;
	  }
    return head;
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

	head=RemoveDuplicatesII(head);

	printList(head);

	
}