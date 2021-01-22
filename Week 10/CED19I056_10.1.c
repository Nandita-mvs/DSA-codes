//Recursive implementation of a Binary Search Tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root;

//function to insert a node in BST
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

//function to find the minimum element in BST
struct node *findmin(struct node *root)
{
    if((root==NULL) || (root->left==NULL))
    {
        return root;
    }
    else
    {
        return findmin(root->left);
    }
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

//Function to search for an element in BST
int search(struct node *root,int key,int height)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->data == key)
    {
        return height;
    }
    if(root->data > key)
    {
        return search(root->left,key,height+1);
    }
    else
    {
        return search(root->right,key,height+1);
    }
}

//Post order traversal of a BST
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}


//In order traversal of a BST
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

//Pre order traversal of a BST
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int choice,value;

	while(1)
    {
        printf ("\nBINARY TREE \n");
        printf (" __________________________________________\n");
        printf ("|     1)   INSERT                          |\n");
        printf ("|     2)   SEARCH                          |\n");
        printf ("|     3)   FIND MINIMUM                    |\n");
        printf ("|     4)   FIND MAXIMUM                    |\n");
        printf ("|     5)   IN-ORDER                        |\n");
        printf ("|     6)   PRE-ORDER                       |\n");
        printf ("|     7)   POST-ORDER                      |\n");
        printf ("|     8)   EXIT                            |\n");
        printf ("|__________________________________________|\n");

		printf("Enter your choice:");
		scanf("%d",&choice);
        
		switch(choice)
		{
			case 1:
			    printf("Enter the element you want to insert:");
                scanf("%d",&value);
                root=Insert(value,root);
				break;

            case 2:
                printf("Enter the value to search in the tree:");
                scanf("%d",&value);
                value=search(root,value,0);
                if(value==-1)
                {
                    printf("NO , The element is not present in the BST\n");
                }
                else
                {
                    printf("YES ,The element is present at height %d\n",value);
                }
                break;

            case 3:
                if(root==NULL)
                {
                    printf("The tree is empty\n");
                }
                else
                {
                    printf("The minimum element in the tree is:%d",findmin(root)->data);
                }
                break;

            case 4:
                if(root==NULL)
                {
                    printf("The tree is empty\n");
                }
                else
                {
                    printf("The minimum element in the tree is:%d",findmax(root)->data);
                }
                break;

            case 5:
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

            case 6:
                if(root==NULL)
                {
                    printf("The tree is empty\n");
                }
                else
                {
                    printf("The elements in the tree are: \n");
                    preorder(root);
                }
                break;

            case 7:
                if(root==NULL)
                {
                    printf("The tree is empty\n");
                }
                else
                {
                    printf("The elements in the tree are: \n");
                    postorder(root);
                }
                break;
            case 8:
                exit(0);

            default:
                printf("Wrong choice!\n");
		}
    }
}

