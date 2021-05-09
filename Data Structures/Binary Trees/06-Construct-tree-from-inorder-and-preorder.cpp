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
