 
#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //constructor
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};



void insertTail(Node *&list,int d)
{
    Node *n=list;
	// n->next=NULL;

	if(list==NULL)
	{
		list=new Node(d);
		return;
	} 
	while(n->next!=NULL) {
	    n=n->next;
	}

	n->next=new Node(d);
}


///////////////////////////////////***********METHOD-I*************/////////////////////////////
Node* findIntersection(Node* head1, Node* head2)
{
    Node *list=NULL;
    
    Node *a=head1;
    Node *b=head2;
    
    while(a and b)
    {
        if(a->data==b->data)
        {
            insertTail(list,a->data);
            a=a->next,b=b->next;
        }
        else if(a->data<b->data)
        a=a->next;
        else
        b=b->next;
    }
    
    return list;
    // Your Code Here
}

///////////////////////////////////***********METHOD-II*************/////////////////////////////
Node* findIntersectionRecursive(Node* head1, Node* head2)
{
    if(head1==NULL or head2==NULL)
    return NULL;
    
    if(head1->data<head2->data)
    return findIntersection(head1->next,head2);
    
    if(head1->data>head2->data)
    return findIntersection(head1,head2->next);
    
    // struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    Node *temp=new Node(head1->data);
    
    // temp->data=head1->data;
    
    temp->next=findIntersection(head1->next,head2->next);
    return temp;
}
void printList(Node *head)
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
    Node *head1=NULL;
    Node *head2=NULL;
    insertTail(head1,3);
    insertTail(head1,20);
    insertTail(head1,100);
    insertTail(head1,101);
    printList(head1);

    insertTail(head2,12);
    insertTail(head2,20);
    insertTail(head2,150);
    insertTail(head2,744);
    printList(head2);
    // node *now=SwapNodePairwiseIII(head);
    Node *list=findIntersectionRecursive(head1,head2);
    printList(list);

}