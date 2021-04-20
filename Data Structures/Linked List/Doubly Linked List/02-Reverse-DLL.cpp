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
////////////////////////////////*******METHOD-I**************////////////////////
// O(n) time   and   O(1) space
node* Reverse(node *head)
{
	node *temp=head;
    if(!head or !(head->next))
    return head;
    
    node *prev=NULL;
    
    while(temp)
    {
        node *n=temp->next;
        node *m=temp->prev;
        
        temp->next=m;
        temp->prev=n;
        
        prev=temp;
        
        temp=n;
    }
    
    return prev;
}

//////////////////////***********METHOD-II************/////////////////////////
//Using Stacks

//use stack and store data of each node in it
//then traverse again and change each node's data and start removig data from stack
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
	insertAtBegin(head,78);
	insertAtBegin(head,7845);
	insertAtBegin(head,7825);
	insertAtBegin(head,78123);
	printList(head);

	head=Reverse(head);
	printList(head);
}
