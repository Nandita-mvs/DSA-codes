#include<stdio.h>
struct node* delete(struct node *root,int value)
{
    if(root==NULL)
    {
        return root;
    }
    else if(value < root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=delete(root->right,value);
    }
    else
    {
        if(root->left==NULL & root->right==NULL)
        {
            free root;
            root
        }
    }
    
}