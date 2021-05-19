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


// finding floor of a number in BST
node* res=NULL;
node* findfloor(node* root,int key)
{
	if(root==NULL)
		return res;

	if(root->data==key)
		return root;

	if(root->data>key)
	{
		root=findfloor(root->left,key);
	}
	else
	{
		res=root;
		root=findfloor(root->right,key);
	}
	return root;
}
// SC for iterative solution is O(1)
node* findflooriterative(node* root,int key)
{
	node* res=NULL;

	while(root!=NULL)
	{
		if(root->data==key)
			return root;

		if(root->data>key)
		{
			root=root->left;
		}
		else
		{
			res=root;
			root=root->right;
		}
	}

	return res;
}


// finding ceil of a number in BST
node* findceiliterative(node* root,int key)
{
	node* res=NULL;

	while(root!=NULL)
	{
		if(root->data==key)
			return root;

		if(root->data>key)
		{
			res=root;
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}

	return res;
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

	int a[]={8,3,10,1,6,14,55,7,13};

	for(auto x:a)
	{
		root=insert(root,x);
	}

	printBSTinorder(root);
	cout<<endl;
	node* ans=findfloor(root,0);

	if(!ans)
		cout<<-1<<endl;
	else
		cout<<ans->data<<endl;
	
	ans=findceiliterative(root,0);

	if(!ans)
		cout<<-1<<endl;
	else
		cout<<ans->data<<endl;


}