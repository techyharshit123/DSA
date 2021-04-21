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