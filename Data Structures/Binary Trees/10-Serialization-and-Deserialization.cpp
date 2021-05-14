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

//***************SERIALIZATION**************///////////

std::vector<int> serializedTree;
void SERIALIZATION(node* root)
{
    if(root==NULL)
    {
        serializedTree.push_back(-1);
        return; 
    }

    serializedTree.push_back(root->data);
    SERIALIZATION(root->left);
    SERIALIZATION(root->right);

}


//***************DESERIALIZATION**************///////////
int index=0;
node* DESERIALIZATION(vector<int>&v)
{
    if(index==v.size())
    {
        return NULL; 
    }

    int val=v[index];
    index++;

    if(val==-1)
        return NULL;

    node* root=new node(val);

    root->left=DESERIALIZATION(v);
    root->right=DESERIALIZATION(v);

    return root;
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
    SERIALIZATION(root);

    for(auto x:serializedTree)
        cout<<x<<" ";
    cout<<endl;
    root=DESERIALIZATION(serializedTree);

    serializedTree.clear();
    SERIALIZATION(root);

    for(auto x:serializedTree)
        cout<<x<<" ";


}