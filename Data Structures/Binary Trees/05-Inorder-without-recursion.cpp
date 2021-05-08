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

////////////////////////////////*****************METHOD-1*******************////////////////////////////////////
//WITH STACK

void inOrder(node* root)
{
    stack<node*>s;

    node* curr=root;

    while(curr!=NULL or s.size()>0)
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

        //Curr is NULL at this point
        curr=s.top();

        //node is processed
        s.pop();

        cout<<curr->data<<" ";

        curr=curr->right; //after visiting the left subtree we are back at root node and now visiting the right subtree
    }
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

    inOrder(root);
}