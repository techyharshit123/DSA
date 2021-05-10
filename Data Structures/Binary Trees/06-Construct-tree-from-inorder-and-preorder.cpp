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

//////////////////////////***********METHOD-1*****************//////////////////
// TC=O(n^2) and SC=O(n);

int preIndex=0;
node* build(int in[],int pre[],int is,int ie)
{
	if(is>ie)
		return NULL;

	node* root=new node(pre[preIndex]);
	preIndex++;

	int inIndex;
	for(int i=is;i<=ie;i++)
	{
		if(in[i]==root->data)
		{
			inIndex=i;
			break;
		}
	}

	root->left=build(in,pre,is,inIndex-1);
	root->right=build(in,pre,inIndex+1,ie);

	return root;
}

////////////////////********************MRTHOD-2**********************///////////////////
//Using Hashmap
//Store the key and value pair of all the elements of the inorder array with array element as the key of map and index as the value;



//Printing the tree in Post Order manner
void printPostOrder(node* root)
{
	if(root==NULL)
		return;


	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main()
{
	int n;
	cin>>n;
	
	int inorder[n], preorder[n];
	for(int i=0; i<n; i++)
		cin>> inorder[i];
	for(int i=0; i<n; i++)
		cin>> preorder[i];

	node* root=build(inorder,preorder,0,n-1);
	printPostOrder(root);
}
