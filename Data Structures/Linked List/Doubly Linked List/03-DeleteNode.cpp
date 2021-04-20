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

node* deleteNode(node *head, int x)
{
    if(head==NULL)
    return head;
    int cnt=1;
    if(x==1)
    {
        node *next=head;
        head=head->next;
        head->prev=NULL;
        delete(next);
        return head;
    }
    
    node *temp=head;
    while(cnt!=x)
    {
        temp=temp->next;
        cnt++;
    }
    
    node *del=temp;
    del=del->prev;
    del->next=temp->next;
    
    if(temp->next)
    {
        temp->next->prev=del;
    }
    delete(temp);
    return head;
  //Your code here
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
	insertAtBegin(head,78);
	insertAtBegin(head,7845);
	insertAtBegin(head,7825);
	insertAtBegin(head,78123);
	printList(head);
	head=deleteNode(head,2);
	printList(head);
}
