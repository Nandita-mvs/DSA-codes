//Program to implement AVL tree
#include<stdio.h>
#include <stdlib.h>

//Node declaration
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

//Function to create a new node
struct node *newNode(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;

    return temp;
}

//Function to return max of two numbers
int maximum(int a,int b)
{
    return((a>b)?a:b);
}

//Function to find the height of a subtree
int height(struct node *pointer)
{
    if(pointer==NULL)
    {
        return 0;
    }
    return (pointer->height);
}

//Function to caluculate the balance factor
int balance_fac(struct node* ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    return height(ptr->left)-height(ptr->right);
}

//Funtion to Left rotate
struct node *leftrotate(struct node* ptr)
{
    struct node *a = ptr->right;
    struct node *y=a->left;

    a->left=ptr;
    ptr->right=y;

    ptr->height=1+maximum(height(ptr->left),height(ptr->right));
    a->height=1+maximum(height(a->left),height(a->right));

    return a;
}

//Function to right rotate
struct node *rightrotate(struct node* ptr)
{
    struct node *a=ptr->left;
    struct node *y=a->right;

    a->right=ptr;
    ptr->left=y;

    ptr->height=1+maximum(height(ptr->left),height(ptr->right));
    a->height=1+maximum(height(a->left),height(a->right));

    return a;
}

//Function to find the inorder successor
struct node *inorderSucc(struct node *ptr)
{
    struct node *temp=ptr;
    while(temp->left != NULL)
    {
        temp=temp->left;
    }
    return temp;
}

//Function to insert a new node
struct node *insert(struct node *ptr,int value)
{
    if(ptr==NULL)
    {
        return newNode(value);
    }
    if(value < ptr->data)
    {
        ptr->left=insert(ptr->left,value);
    }
    else if(value > ptr->data)
    {
        ptr->right=insert(ptr->right,value);
    }
    else
    {
        return ptr;
    }

    ptr->height = 1 + maximum(height(ptr->left),height(ptr->right));
    int balance = balance_fac(ptr);

    //   left-                 left
    if(balance > 1  && value < ptr->left->data)
    {
        return rightrotate(ptr);
    }
    //  left -              right
    if(balance > 1 && value > ptr->left->data)
    {
        ptr->left=leftrotate(ptr->left);
        return rightrotate(ptr);
    }
    //right                  -right
    if(balance < -1 && value > ptr->right->data)
    {
        return leftrotate(ptr);
    }
    //right-                        left
    if(balance < -1 && value < ptr->right->data)
    {
        ptr->right=rightrotate(ptr->right);
        return leftrotate(ptr);
    }

    return ptr;
}

//Function to delete a node with given value
struct node* delete(struct node *ptr,int value)
{
   if(ptr==NULL)
   {
       return ptr;
   }
   if(value < ptr->data)
   {
       ptr->left=delete(ptr->left,value);
   }
   else if(value > ptr->data)
   {
       ptr->right=delete(ptr->right,value);
   }
   else
    {
        if(ptr->left == NULL || ptr->right==NULL)
        {
            struct node *temp = ptr->left ? ptr->left : ptr->right;

            if(temp==NULL)
            {
                temp=ptr;
                ptr=NULL;
            }
            else
            {
                *ptr=*temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp=inorderSucc(ptr->right);
            ptr->data=temp->data;
            ptr->right=delete(ptr->right,temp->data);
        }
    }
    if(ptr==NULL)
    {
        return ptr;
    }
    ptr->height=1+maximum(height(ptr->left),height(ptr->right));
    int balance= balance_fac(ptr);

    //left-left
    if(balance >1 && balance_fac(ptr->left) >= 0)
    {
        return rightrotate(ptr);
    }
    //left-right
    if(balance > 1 && balance_fac(ptr->left) < 0)
    {
        ptr->left=leftrotate(ptr->left);
        return rightrotate(ptr);
    }
    //right-right
    if(balance < -1 && balance_fac(ptr->right) <= 0)
    {
        return leftrotate(ptr);
    }
    //right-left
    if(balance < -1 && balance_fac(ptr->right) > 0)
    {
        ptr->right=rightrotate(ptr->right);
        return leftrotate(ptr);
    }

    return ptr;
}

//Preorder traversal of AVL tree
void preorder(struct node *ptr)
{
	printf("Preorder Traversal\n");

    if(ptr==NULL)
    {
        return;
    }
    printf("%d  ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

int main()
{
    struct node* root=NULL;
    int value;
    int choice;

    while(1)
    {
        printf ("\nAVL TREE\n");
        printf ("|--------------------|\n");
        printf ("|      1)INSERT      |\n");
        printf ("|      2)DELETE      |\n");
        printf ("|      3)DISPLAY     |\n");
        printf ("|      4)EXIT        |\n");
        printf ("|--------------------|\n");

		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
            case 1:
                printf("Enter the value to insert:");
                scanf("%d",&value);
                root=insert(root,value);
				preorder(root);
				break;

            case 2:
                printf("Enter the value to delete:");
                scanf("%d",&value);
                root=delete(root,value);
                preorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice!");
		}
    }
}

