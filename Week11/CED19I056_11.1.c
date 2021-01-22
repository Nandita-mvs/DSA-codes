#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root=NULL;

//Function to insert a node in BST
struct node* Insert(int value,struct node* root)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        root->left=NULL;
        root->right=NULL;
    }
    else if(newnode->data < root->data)
    {
        root->left=Insert(value,root->left);
    }
    else
    {
        root->right=Insert(value,root->right);
    }
    return root;
}

//Funtion for inorder traversal of BST
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}



//Function to find the minimum element in BST
struct node *findmin(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

//Function to find the maximum element in the BST
struct node *findmax(struct node* root)
{
    if((root==NULL) || (root->right==NULL))
    {
        return root;
    }
    else
    {
        return findmax(root->right);
    }
}

//Function to find the inorder predecessor of a given node in BST
struct node* inpredecessor(struct node *root,struct node *pred,int value)
{
    if(root==NULL)
    {
        return pred;
    }
    if(root->data == value)
    {
        if(root->left!=NULL)
        {
            return findmax(root->left);
        }
    }
    else if(root->data > value)
    {
        return inpredecessor(root->left,pred,value);
    }
    else
    {
        pred=root;
        return inpredecessor(root->right,pred,value);
    }
    return pred ? pred : NULL ;
    
}

//Function to find the inorder successor of a given node in BST
struct node* insuccessor(struct node *root,struct node *succ,int value)
{
    if(root==NULL)
    {
        return succ;
    }
    if(root->data == value)
    {
        if(root->right!=NULL)
        {
            return findmin(root->right);
        }
    }
    else if(root->data > value)
    {
        succ=root;
        return insuccessor(root->left,succ,value);
    }
    else
    {
        return insuccessor(root->right,succ,value);
    }
    return succ ? succ : NULL ;
    
}

//Function to search for an element in BST
struct node* search(struct node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data == key)
    {
        return root;
    }
    if(root->data > key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}

//Function to delete a node in BST
struct node* delete(struct node *root,int value)
{
    struct node *temp,*child;
    if(root==NULL)
    {
        return NULL;
    }
    if( value < root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=delete(root->right,value);
    }

    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left && root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL && root->right)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else
        {
             temp=root->right;
            while(temp->left != NULL)
            {
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
        return root;
    }   
}


int main()
{
    int choice,value;
    struct node *temp;

	while(1)
    {
        printf ("\nBINARY TREE \n");
        printf (" __________________________________________\n");
        printf ("|     1)   INSERT                          |\n");
        printf ("|     2)   IN-ORDER                        |\n");
        printf ("|     3)   DELETE                          |\n");
        printf ("|     4)   PREDECESSOR                     |\n");
        printf ("|     5)   SUCCESSOR                       |\n");
        printf ("|     6)   EXIT                            |\n");
        printf ("|__________________________________________|\n");

        printf("Enter the choice number:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	printf("Enter the element you want to insert:");
                scanf("%d",&value);
                root=Insert(value,root);
				break;
            
            case 2:
                if(root==NULL)
                {
                    printf("The tree is empty\n");
                }
                else
                {
                    printf("The elements in the tree are: \n");
                    inorder(root);
                }
                break;

            case 3:
                printf("Enter the value you want to delete:");
                scanf("%d",&value);
                temp=search(root,value);
                if(temp==NULL)
                {
                    printf("The element is not present in BST");
                }
                else
                {
                    delete(root,value);
                }
                break;

            case 4:
                printf("Enter the element for which you want in-order predecessor:");
                scanf("%d",&value);
                temp=inpredecessor(root,NULL,value);
                if(temp==NULL)
                {
                    printf("The in-order predecessor is NULL\n");
                }
                else
                {
                    printf("The in-order predecessor is %d",temp->data);
                }
                break;
                
            case 5:
                printf("Enter the element for which you want in-order successor:");
                scanf("%d",&value);
                temp=insuccessor(root,NULL,value);
                if(temp==NULL)
                {
                    printf("The in-order succcessor is NULL\n");
                }
                else
                {
                    printf("The in-order successor is %d",temp->data);
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Wrong choice ! Please enter again\n");
        }
    }
}


