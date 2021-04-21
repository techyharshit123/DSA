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

node* addToEmpty(node* last, int data)
{
	// This function is only for empty list
	if (last != NULL)
	return last;

	// Creating a node dynamically.
	node* temp =new node(data);
	last = temp;

	// Creating the link.
	last -> next = last;

	return last;
}

node* addBegin(node* last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	node* temp =new node(data);
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

node* addEnd(node* last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);
	
	node* temp =new node(data);
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

node* addAfter(node* last, int data, int item)
{
	if (last == NULL)
		return NULL;

	node* temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = new node(data);
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while(p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}

void traverse(node* last)
{
	node* p;

	// If list is empty, return.
	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first Node of the list.
	p = last -> next;

	// Traversing the list.
	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	while(p != last->next);

}

// Driven Program
int main()
{
	node* last = NULL;

	last = addToEmpty(last, 6);
	last = addBegin(last, 4);
	last = addBegin(last, 2);
	last = addEnd(last, 8);
	last = addEnd(last, 12);
	last = addAfter(last, 10, 8);

	traverse(last);

	return 0;
}
