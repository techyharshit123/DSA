#include <bits/stdc++.h>
 
using namespace std;

class Binary_Tree_Node
{
public:
	int data;
	Binary_Tree_Node* left;
	Binary_Tree_Node* right;

	Binary_Tree_Node(int d)
	{
		data=d;
		left=right=NULL;
	}
};


///////TC=O(n) and SC=O(n)
/////////////////////////////////////////*********METHOD-1***************//////////////////
vector<int> BFS(Binary_Tree_Node* root)
{
	vector<int>v;
    if(root==NULL)
    return v;
    
    queue<Binary_Tree_Node *>q;
    q.push(root);
    
    while(!q.empty())
    {
        
        Binary_Tree_Node* n=q.front();
        v.push_back(n->data);
        q.pop();
        
        if(n->left)
        q.push(n->left);
        if(n->right)
        q.push(n->right);
    }
    
    return v;
}

/////////////////////////////////////////*********METHOD-2***************//////////////////
void BFSlinebyline(Binary_Tree_Node* root)
{
    if(root==NULL)
    return;
    
    queue<Binary_Tree_Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        
        Binary_Tree_Node* n=q.front();

        if(n==NULL)
        {
        	q.push(NULL);
        	cout<<endl;
        	q.pop();
        	continue;
        }
        cout<<n->data<<" ";
        q.pop();
        
        if(n->left)
        q.push(n->left);
        if(n->right)
        q.push(n->right);
    }
    
    return;
}

/////////////////////////////////////////*********METHOD-3***************//////////////////
void BFSlinebyline2(Binary_Tree_Node* root)
{
    if(root==NULL)
    return;
    
    queue<Binary_Tree_Node *>q;
    q.push(root);
    while(!q.empty())
    {
    	int cnt=q.size();

    	for(int i=0;i<cnt;i++)
    	{
    		Binary_Tree_Node* n=q.front();
    		cout<<n->data<<" ";
	        q.pop();
	        
	        if(n->left)
	        q.push(n->left);
	        if(n->right)
	        q.push(n->right);
    	}
    	cout<<endl;
    }
    
    return;
}
int main()
{

}