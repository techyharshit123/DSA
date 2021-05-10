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

////////////////////*****************METHOD-0***************////////////////////
//USING RECURSION
// TC=O(n^2)

// Function to print spiral traversal of a tree
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;
  
    // ltr -> Left to Right. If this variable
    // is set,then the given level is traversed 
    // from left to right. 
    bool ltr = false;
    for(i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, ltr);
  
        // Revert ltr to traverse next 
        // level in opposite order
        ltr = !ltr;
    }
}
  
// Print nodes at a given level 
void printGivenLevel(struct node* root, 
                     int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
          
    else if (level > 1) 
    {
        if (ltr)
        {
            printGivenLevel(root->left, 
                            level - 1, ltr);
            printGivenLevel(root->right,
                            level - 1, ltr);
        }
        else 
        {
            printGivenLevel(root->right, 
                            level - 1, ltr);
            printGivenLevel(root->left,
                            level - 1, ltr);
        }
    }
}
  
// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else 
    {
          
        // Compute the height of each subtree 
        int lheight = height(node->left);
        int rheight = height(node->right);
  
        // Use the larger one 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
  

///////////////////////************METHOD-1******************/////////////////////////
//Using Deque

vector<int> findSpiral(node *root)
{
    vector<int>v;
    if(root==NULL)
    return v;
    
    bool odd=true;
    
    deque<node*>dq;
    
    dq.push_back(root);
    while(!dq.empty())
    {
        int cnt=dq.size();
        
        if(!odd)
        {
            for(int i=0;i<cnt;i++)
            {
                node* curr=dq.front();
                
                v.push_back(curr->data);
                dq.pop_front();
                
                if(curr->left)
                dq.push_back(curr->left);
                if(curr->right)
                dq.push_back(curr->right);
            }
            odd=true;
        }
        else
        {
            for(int i=0;i<cnt;i++)
            {
                node* curr=dq.back();
                
                v.push_back(curr->data);
                dq.pop_back();
                
                
                if(curr->right)
                dq.push_front(curr->right);
                if(curr->left)
                dq.push_front(curr->left);
            }
            odd=false;   
        }
    }
    
    return v;
    
    //Your code here
}

///////////***************METHOD-2*****************/////////////////////
// Using one queue and one stack
// BUT IN THSI CASE SOME OF THE ITEMS ARE PROCESSED 4 TIMES


/////////////////////*********************METHOD-3***************///////////////////////
//Using 2 stacks
//EFFICIENT METHOD AS EACH ITEMS IS PROCESSED EXACTLY ONCE


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

    std::vector<int> v=findSpiral(root);

    for(auto x:v)
    	cout<<x<<" ";
}