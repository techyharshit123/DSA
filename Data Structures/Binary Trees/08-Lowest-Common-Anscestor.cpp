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

//////////////////////////////////////////**************METHOD-1**************/////////////////////////////
//3 traversal occurs and the time complexity id Theta(n)
std::vector<node*> path1;
std::vector<node*> path2;
bool find(node* root,vector<node*>&path,int n)
{
	if(root==NULL)
	{
		return false;
	}

	if(root->data==n)
	{
		path.push_back(root);
		return true;
	}

	bool findinLeftChild=find(root->left,path,n);

	if(findinLeftChild)
	{
		path.push_back(root);
		return true;
	}

	bool findinRightChild=find(root->right,path,n);

	if(findinRightChild)
	{
		path.push_back(root);
		return true;
	}

	return false;
}

node* lca(node* root,int n1,int n2)
{
	if(find(root,path1,n1)==false or find(root,path2,n2)==false)
		return NULL;

	int i=path1.size()-1;
	int j=path2.size()-1;
		
	while(i>=0 and j>=0 and path1[i]==path2[j])
	{
		i--;
		j--;
	}

	i++;
	j++;

	return path1[i];
}	


//////////////////////////////////////////**************METHOD-2**************/////////////////////////////
//Efficient method
//Requires one traversal and Theta(h) extra space for the recursive traversal
//Assume that both n1 and n2 exist. Does not give correct result when only one of n1 or n2 exists
//Also this method requires less space in the worst case
node* lcaOptimised(node* root,int n1,int n2)
{
	if(root==NULL)
    return NULL;
    
    if(root->data==n1 or root->data==n2)
    return root;
    
    //search in the left and right subtree
    node* leftans=lcaOptimised(root->left,n1,n2);
    node* rightans=lcaOptimised(root->right,n1,n2);
    
    if(leftans!=NULL and rightans!=NULL)
    return root;
    
    if(leftans!=NULL)
    return leftans;
    
    if(rightans!=NULL)
    return rightans;
    
    return NULL;
}
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

    int n1,n2;
    cin>>n1>>n2;
    node* lcaroot=lcaOptimised(root,n1,n2);

    cout<<lcaroot->data;
}
