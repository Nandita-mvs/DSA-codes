#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
struct node *create()
{
	struct node *newNode;
	int value;
	printf("Enter data(-1 for no data):");
	scanf("%d",&value);

	if(value==-1)
    {
        return NULL;
    }

	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=value;

	printf("Enter left child of %d:\n",value);
	newNode->left=create();

	printf("Enter right child of %d:\n",value);
	newNode->right=create();

	return newNode;
}

void postorder(struct node *tree)
{
    if(tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->data);
    }
}

void inorder(struct node *tree)
{
    if(tree != NULL)
    {
        inorder(tree->left);
        printf("%d\t",tree->data);
        inorder(tree->right);
    }
}

void preorder(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

int height(struct node *tree)
{
    int lheight,rheight;
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        lheight=height(tree->left);
        rheight=height(tree->right);
        if(lheight > rheight)
        {
            return (lheight+1);
        }
        else
        {
            return (rheight+1);
        }
    }
}
int heightNode(struct node *root,int value, int height)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->data == value)
    {
        return height;
    }
    int level=heightNode(root->left,value,height+1);

    if(level != 0)
    {
        return level;
    }
    return heightNode(root->right,value,height+1);

}
int main()
{
    int choice,value;


	while(1)
    {
        printf ("\nBINARY TREE \n");
        printf ("-------------------------------------------\n");
        printf ("      1    CREATE                         \n");
        printf ("      2    HEIGHT OF NODE                  \n");
        printf ("      3    HEIGHT OF TREE                  \n");
        printf ("      4    IN-ORDER                        \n");
        printf ("      5    PRE-ORDER                       \n");
        printf ("      6    POST-ORDER                      \n");
        printf ("      7    EXIT                            \n");
        printf ("-------------------------------------------\n");

		printf("Enter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			    printf("CREATING TREE\n");
                struct node *tree;
                tree=create();
				break;

            case 2:
                printf("Enter the value of the node for which you want the height:");
                scanf("%d",&value);
                printf("The height of the node is %d",heightNode(tree,value,1));
                break;

            case 3:
                printf("The height of tree is %d\n",height(tree));
                break;

            case 4:
                printf("The elements in the tree are: \n");
                inorder(tree);
                break;

            case 5:
                printf("The elements in the tree are: \n");
                preorder(tree);
                break;

            case 6:
                printf("The elements in the tree are: \n");
                postorder(tree);
                break;

            case 7:
                exit(0);

            default:
                printf("Wrong choice!");
		}
    }
}

