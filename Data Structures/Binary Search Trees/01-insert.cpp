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

}