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


// Insert in BST
node* insert(node* root, int key)
{
	if(root==NULL)
	{
		node* newNode=new node(key);
		return newNode;
	}

	if(key<root->data)
	{
		root->left=insert(root->left,key);
	}
	else
	{
		root->right=insert(root->right,key);
	}


	return root;
}

node* getInorderSuccessor(node* root)
{
	node* curr=root->right;

	while(curr!=NULL and curr->left!=NULL)
	{	
		curr=curr->left;
	}

	return curr;
}

//The worst case time complexity of delete operation is O(h) where h is the height of the Binary Search Tree. In worst case, we may have to travel from the root to the deepest leaf node. The height of a skewed tree may become n and the time complexity of delete operation may become O(n)
node* deleteNode(node* root,int key)
{
	if(root==NULL)
		return root;

	if(key<root->data)
	{
		root->left=deleteNode(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=deleteNode(root->right,key);
	}
	else
	{
		// if node with one children
		if(root->left==NULL)
		{
			node* temp=root->right;
			delete(root);
			return temp;
		}
		// if node with one children
		else if(root->right==NULL)
		{
			node* temp=root->left;
			delete(root);
			return temp;
		}
		else
		{
			// get the inorder successor of root(smallest in the right subtree)
			node *temp=getInorderSuccessor(root);
			root->data=temp->data;
			// now delete this temp leaf node (inorder successor) as the normal method
			root->right=deleteNode(root->right,temp->data);
		}
	}
	return root;
}


//////////////////////////////////////////***************METHOD-2*****************////////////////////////////////////////////

/////////To optimise the code we can simply keep an pointer to previous of successor node so that we need not traverse the tree again for deleting the successor node
//
//In the above recursive code, we recursively call delete() for the successor. We can avoid recursive calls by keeping track of the parent node of the successor so that we can simply remove the successor by making the child of a parent NULL. We know that the successor would always be a leaf node.
node* deleteNodeOptimised(node* root,int key)
{
	if(root==NULL)
		return root;

	if(key<root->data)
	{
		root->left=deleteNode(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=deleteNode(root->right,key);
	}
	else
	{
		// if node with one children
		if(root->left==NULL)
		{
			node* temp=root->right;
			delete(root);
			return temp;
		}
		// if node with one children
		else if(root->right==NULL)
		{
			node* temp=root->left;
			delete(root);
			return temp;
		}
		else
		{
			node* successorParent=root;

			//find the successor
			node* successor=root->right;

			while(successor!=NULL and successor->left!=NULL)
			{	
				successorParent=successor;
				successor=successor->left;
			}

			if(successorParent==root)
			{
				successorParent->right=successor->right;
			}
			else
			{
				successorParent->left=successor->right;
			}
			
			root->data=successor->data;
			delete(successor);
			
		}
	}
	return root;
}

// print BST in inorder fashion
void printBSTinorder(node * root)
{
	if(root==NULL)
		return;

	//left root right
	printBSTinorder(root->left);
	cout<<root->data<<" ";
	printBSTinorder(root->right);
}
int main()
{
	node* root=NULL;

	int a[]={8,3,10,1,6,14,4,7,13};

	for(auto x:a)
	{
		root=insert(root,x);
	}

	printBSTinorder(root);
	cout<<endl;

	root=deleteNodeOptimised(root,1);

	printBSTinorder(root);
	cout<<endl;


}