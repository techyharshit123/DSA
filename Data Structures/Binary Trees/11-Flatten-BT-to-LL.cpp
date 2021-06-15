//Harshit

#include "bits/stdc++.h"
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//Method1-recursive
void flatten(node* root) {
    if (root == NULL)
        return;
    if (root->left == NULL and root->right == NULL)
        return;

    // dono subtree ko flatten krlo
    flatten(root->left);
    flatten(root->right);

    if (root->left)
    {
        //store right subtree in temp
        node* temp = root->right;

        //attach left subtree at root's right and making root's left NULL
        root->right = root->left;
        root->left = NULL;

        //finding the tail of root's right which was previously root's left
        //purpose of finding tail is that at tail only we'll be attaching our temp subtree
        node* tailleft = root->right;
        while (tailleft->right)
        {
            tailleft = tailleft->right;
        }
        //ataching the temp tree at tail's right
        tailleft->right = temp;

    }
}


//method2->using stack
void flatten2(node* root) {
    if (root == NULL)
        return;

    stack<node*>s;

    s.push(root);

    while (!s.empty())
    {
        node* curr = s.top();
        s.pop();

        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }

        if (!s.empty())
        {
            curr->right = s.top();
        }
        curr->left = NULL;
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

    flatten(root);
}