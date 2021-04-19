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

////////////////////////////////////////*****USING STACK*****///////////////////////////////////////
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

	node *ans=divide(head);

	printList(ans);
	
}