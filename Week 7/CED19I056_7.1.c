//dOUBLE LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
} *start=NULL, *current, *newNode ;

int ListLength()
{
    int count=0;
    if(start==NULL)
    {
        count=0;
        return count;
    }
    current=start;

  while (current != NULL)
  {
        current = current->next;
        count++;
  }
    return count;
}

int InsertB(int value)
{
    newNode=(struct node *) malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=value;
    if(start==NULL)
    {
        start=newNode;
        newNode->next=NULL;
    }
    else
    {
        newNode->next=start;
        start->prev=newNode;
        start=newNode;
    }

}

int InsertE(int value)
{
    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
	current=start;
	if(start==NULL)
    {
        start=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
    }
    else
    {
        while(current->next != NULL )
        {
            current= current->next;
        }
        newNode->prev=current;
        current->next=newNode;
        newNode->next=NULL;
    }

}

int InsertValue(int key, int value)
{
    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
    current=start;
    if(current->data==key)
    {
        InsertB(key);
    }
    else
        {
            while(current->data != key )
            {
                if(current->next==NULL)
                {
                    InsertE(value);
                    return 0;
                }
                else if(current == NULL)
                {
                    printf("Value not present");
                    return 0;
                }

                current= current->next;
            }
        newNode->prev=current;
        newNode->next=current->next;
        current->next->prev=newNode;
        current->next=newNode;
    }
}
int InsertPosition(int position,int value)
{
    int i=0;
    int count=ListLength();
    if(position > count)
    {
        printf("Node not present\n");
        return 0;
    }

    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
    current=start;

    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        current=start;
        i=0;
        while(i<position-1 && current!=NULL)
            {
                current = current->next;
                i++;
            }
            if(current != NULL)
            {
                newNode->next = current->next;
                newNode->prev = current;
                if(current->next != NULL)
                {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
            else
            {
                printf("Error, Invalid position\n");
            }
        }
}

int DeleteB()
{
    current=start;

    if(start==NULL)
    {
        printf("List Empty\n");
    }
    else if(start->next==NULL)
    {
        start=NULL;
        free(start);

    }
    else
    {
        start=current->next;
        start->prev=NULL;
        free(current);
    }

}

int DeleteE()
{
    current=start;
    if(start==NULL)
    {
        printf("Underflow\n");
    }
    else if(start->next==NULL)
    {
        start=NULL;
        free(start);

    }
    else
    {
        while(current->next != NULL )
        {
            current = current->next;
        }
        current->prev->next=NULL;
        free(current);
    }
}

int DeleteValue(int key)
{
    struct node *tail;
    tail=start;

    while(tail->next != NULL)
    {
        tail=tail->next;
    }

    current=start;

    if(current->data==key)
    {
        DeleteB();
    }
    else
    {
        while(current->data != key)
        {
            current=current->next;
        }
        if(current==tail)
        {
            DeleteE();
        }
        else
        {
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(current);
        }
    }
}

int DeletePosition(int position)
{
    struct node *last;
    current=start;
    last=start;
    int i=0;

    int count=ListLength();
    if(position > count)
    {
        printf("Node not present\n");
        return 0;
    }
    while(last != NULL)
    {
        last=last->next;
    }

    for(i=1;i<position&&current != NULL;i++)
    {
        current=current->next;
    }

    if(position==1)
        DeleteB();

    else if(current==last)
        DeleteE();

    else if(current != NULL)
    {
        current->prev->next=current->next;

        if(current->next != NULL)
        {
            current->next->prev=current->prev;
        }
        free(current);
    }
    else
    {
        printf("Invalid position\n");
    }

}

int isempty()
{
    if(ListLength()== 0)
        return 1;
    else
        return 0;
}

int Search(int key)
{
    current = start;
    while(current != NULL)
    {
        if(current->data==key)
            return 1;
        current=current->next;
    }
}


int modify(int key,int newNumber)
{
    current = start;
    while(current != NULL)
    {
        if(current->data==key)
            current->data=newNumber;

        else
        {
            current = current ->next;
        }
    }
    if(current == NULL)
    {
        printf("Could not modify,Value not present\n");
    }
}
int display()
{
    struct node *temp;
    current = start; // copy address of start to current
	if(current == NULL)
	{
		printf("The list is empty \n");
	}
	else
    {
        while(current != NULL)
		{
			printf("%d<->", current->data);
			current=current->next;
		}
		printf("NULL \n");
    }
}
int main()
{
	int choice,value,key,search,count,newNumber,position;
	while(1)
    {
        printf ("DOUBLY LINKED LIST\n");
        printf ("------------------------------------------\n");
        printf ("      1    INSERT BEGINNING               \n");
        printf ("      2    INSERT END                     \n");
        printf ("      3    INSERT MIDDLE                  \n");
        printf ("      4    INSERT POSITION                \n");
        printf ("      5    DELETE BEGINNING               \n");
        printf ("      6    DELETE END                     \n");
        printf ("      7    DELETE MIDDLE                  \n");
        printf ("      8    DELETE POSITION                \n");
        printf ("      9    CHECK IS EMPTY                 \n");
        printf ("      10   SEARCH                         \n");
        printf ("      11   LIST LENGTH                    \n");
        printf ("      12   MODIFY                         \n");
        printf ("      13   DISPLAY                        \n");
        printf ("      14   EXIT                           \n");
        printf ("------------------------------------------\n");

		printf("Enter your choice:");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the value to insert in the begining:");
				scanf("%d",&value);
				InsertB(value);
				display();
				break;

            case 2:
                printf("Enter the value to insert in the end:");
                scanf("%d", &value);
                InsertE(value);
                display();
                break;

            case 3:
                printf("Enter the value to insert in the middle:");
                scanf("%d", &value);
                printf("After which element do you want to insert:");
                scanf("%d",&key);

                if(Search(key)==1)
                    InsertValue(key,value);
                else
                    printf("The value entered is not present \n");

                display();
                break;

            case 4:
                printf("Enter the node position to insert:");
                scanf("%d",&position);
                printf("Enter the value:");
                scanf("%d",&value);
                InsertPosition(position,value);
                display();
                break;

            case 5:
                DeleteB();
                display();
                break;


            case 6:
                DeleteE();
                display();
                break;

            case 7:
                printf("Enter the value to delete:");
                scanf("%d",&key);
                if(Search(key)==1)
                    DeleteValue(key);
                else
                    printf("The value entered is not present \n");

                display();
                break;

            case 8:
                printf("Enter the position you want to delete:");
                scanf("%d",&position);
                DeletePosition(position);
                display();
                break;

            case 9:
                if(isempty()== 1)
                    printf("list is Empty\n");
                else
                    printf("List not Empty\n");
                break;

            case 10:
                printf("Enter the key to be searched:");
                scanf("%d",&key);
                if(Search(key)==1)
                    printf("Key is present\n");
                else
                    printf("Key is not present\n");
                break;

            case 11:
                printf("The length of list is %d\n",ListLength());
                break;

            case 12:
                printf("Enter the element you want to modify:");
                scanf("%d",&key);
                printf("Enter the new number:");
                scanf("%d",&newNumber);
                modify(key,newNumber);
                display();
                break;

            case 13:
                display();
                break;

            case 14:
                exit(0);

            default:
                printf("Wrong choice!");
		}
    }
}


