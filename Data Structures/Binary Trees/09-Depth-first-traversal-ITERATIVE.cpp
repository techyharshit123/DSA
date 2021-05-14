//Harshit
 
#include "bits/stdc++.h"
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//////////////////////////////////**************inOrder***************/////////////////////////////
//TC=theta(n) and SC=O(h)
void inOrder(node* root)
{
	stack<node*>s;

	node* curr=root;


	while(curr!=NULL or !s.empty())
	{
		 //reaching the left most node of the curr Node
		while(curr!=NULL)
		{
			/* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
			s.push(curr);
			curr=curr->left;	
		}

		//curr is null at this point 

		curr=s.top();
		s.pop();

		cout<<curr->data<<" ";

		//after visiting the whole left subtree of a root we are back at root node then now moving to its right subtree after printing the content of root
		curr=curr->right;
	}
}

//////////////////////////////////**************preOrder***************/////////////////////////////
//TC=O(n) and SC=O(h);
// idea is to store only the right child and print the left children while processing it
// while processing the left left left children we are correspondingly going to push the right children
void preOrderOptimised(node* root)
{
	stack<node*>s;

	node* curr=root;

	while(curr!=NULL or !s.empty())
	{
		// Print left children while exist
        // and keep pushing right into the
        // stack.
		while(curr!=NULL)
		{
			if(curr->right)
            s.push(curr->right);

			cout<<curr->data<<" ";

			curr=curr->left;
		}

		// We reach when curr is NULL, so We
        // take out a right child from stack
		if(!s.empty())
		{
			curr=s.top();
			s.pop();
		}
	}
}

//Second method idea is similar as level order traversal
// enqueue a node in a data structure print it, push its children to the data struvture and pop the node
// TC=O(n) and SC=O(n)
void preOrder2(node* root)
{
	if(root==NULL)
		return;

	stack<node*>s;

	s.push(root);

	 /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
	while(!s.empty())
	{
		node* curr=s.top();
		cout<<curr->data<<" ";
		s.pop();

		if(curr->right)
			s.push(curr->right);
		if(curr->left)
			s.push(curr->left);


	}
}


//////////////////////////////////**************postOrder***************/////////////////////////////
//using 2 stacks

//only using 1 stack

int main()
{
    /*  Constructed Binary Tree is
                 8
               /   \
              10    3
             /  \    \
            1    6    14 
                / \   /
               9   7 13
    
    */
    node* root = buildTree();

    inOrder(root);
    cout<<endl;
    preOrderOptimised(root);
    cout<<endl;
    preOrder2(root);
}
