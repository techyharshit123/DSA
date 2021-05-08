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

////////////////////////*****************METHOD-1*******************//////////////////////////////
//O(n^2)
int height(node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        return 1+max(height(root->left),height(root->right));
    }
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(node *root)
{
    if(root==NULL)
    {
        return true;
    }
    
    int a=height(root->left);
    int b=height(root->right);
    
    if(abs(a-b)<=1)
    {
        return (isBalanced(root->left) and isBalanced(root->right));
    }
    else
    {
        return false;
    }
    //  Your Code here
}


////////////////////////*****************METHOD-2*******************//////////////////////////////
//O(n)
//Function to check whether a binary tree is balanced or not.

//If return value is -1 then the tree is not height balanced but if return value is >=0 then that is the height of the tree

int isBalancedOptimised(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    //Checking for left subtree and also getting the left height
    int a=isBalancedOptimised(root->left);
    if(a==-1)
    	return -1;

    //checking for right subtree and also getting the right subtree
    int b=isBalancedOptimised(root->right);
    if(b==-1)
    	return -1;
    
    if(abs(a-b)<=1)
    {
        return 1+max(a,b);
    }
    else
    {
        return -1;
    }
    //  Your Code here
}
int main()
{
    node* root = buildTree();


    int x=isBalancedOptimised(root);
    cout<<x<<endl;
    if(x==-1)
    	cout<<"Tree is not height balanced"<<endl;
    else
    	cout<<"Tree is height balanced"<<endl;
}
