//CIRCULAR LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *current;
struct node *newnode;

int display()
{
	current = start; // copy address of start to current

	if(current == NULL)
        printf("EMPTY\n");
    else
    {
        while(current->next != start)
        {
            printf("%d->", current->data);
            current=current->next;
        }
        printf("%d->\n", current->data);
    }
    return 0;
}
int insert_beggining(int num)
{
    newnode=(struct node *)malloc(sizeof(struct node));//creating a node
    newnode->data = num;
    if(start == NULL)//If list is Empty list
    {
        start=newnode;
        newnode->next=newnode;
    }
    else
    {
        current = start;
        while(current->next != start)//to find the last node
        {
            current = current->next;
        }
        current->next=newnode;
        newnode->next=start;
        start=newnode;

    }
    printf("NODE inserted \n");
}
int insert_end(int num)
{
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    current = start;
    if(start == NULL)
    {
        start=newnode;
        newnode->next=newnode;
    }
    else
    {
        while(current->next != start)
            {
                current=current->next;
            }
        current->next=newnode;
        newnode->next=start;
        printf("NODE inserted\n");
    }
}
insert_position(int key,int num)
{
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    current = start;
    if(start == NULL)
    {
        start=newnode;
        newnode->next=newnode;
    }
    else
    {
        while(current->data != key)
            {
                current=current->next;
            }
        newnode->next= current->next;
	    current->next = newnode;
        printf("NODE inserted\n");
    }

}

delete_beggining()
{
    if(start == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        while(current->next != start)
            {
                current=current->next;
            }
        current->next=start->next;
        start=start->next;
    }
}
delete_end()
{
    struct node *previous;
    current=start;
    if(start == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        while(current->next != start)
            {
                previous=current;
                current=current->next;
            }
            previous->next=current->next;
            free(current);
    }
}
int delete_position(int key)
{
    int count;
	struct node *previous;
	if(start == NULL)
    {
        printf("UNDERFLOW\n");
        return 0;
    }
    count=0;
    current= start;
	previous=current;
	while(previous->next!=start)
    {
        previous=previous->next;
        count++;
    }
    int i=0;
	while (i <= count)
    {
        if (current->data == key)
        {
            if (current->next != current)
            {
                previous->next = current->next;
            }
            else
            {
                previous->next = NULL;
            }
            if (current == start)
            {
                start = previous->next;
            }
            free(current);

            if (previous != NULL)
            {
                current = previous->next;
            }
            else
            {
                current = NULL;
            }
        }
        else
        {
            previous = current;
            current  = current->next;
        }
        i++;
   }
}
int count()
{
    int count=0;
    if(start==NULL)
    {
        count=0;
        return count;
    }
    current=start;
    do
    {
        current = current->next;
        count++;
    } while (current != start);
    return count;
}
int main()
{
       int choice;
       int num;
       int position;

   while(1)
   {

       printf("Circular Linked List\n");
       printf("-----------------------------------\n");
       printf("    1 Insert beggining  \n");
       printf("    2 Insert end  \n");
       printf("    3 Insert at a given value  \n");
       printf("    4 delete beggining  \n");
       printf("    5 delete end  \n");
       printf("    6 delete a given value  \n");
       printf("    7 display  \n");
       printf("    8 count  \n");
       printf("    9 exit  \n");
       printf("-----------------------------------\n");
       printf("Enter the choice you want to perform:");
       scanf("%d",&choice);

       switch(choice)
       {
           case 1:
               printf("Enter the number you want to insert:");
               scanf("%d",&num);
               insert_beggining(num);
               display();
               break;
           case 2:
               printf("Enter the number you want to insert:");
               scanf("%d",&num);
               insert_end(num);
               display();
               break;
           case 3:
               printf("After which element do you want to insert?");
               scanf("%d",&position);
               printf("Enter the number you want to insert:");
               scanf("%d",&num);
               insert_position(position,num);
               display();
               break;
           case 4:
               delete_beggining();
               display();
               break;
           case 5:
                delete_end();
                display();
                break;
           case 6:
               printf("which node element do you want to delete?");
               scanf("%d",&position);
               delete_position(position);
               display();
               break;
           case 7:
                display();
                break;
           case 8:
                printf("Number of nodes are %d\n",count());
                break;
           case 9:
                exit(0);
       }
   }
}












