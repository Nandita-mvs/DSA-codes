#include<stdio.h>
#include<stdlib.h>
#include"DLL.h"


int DisplayCurrent()
{
    if(current==NULL)
        return 0;
    printf("Current page is %d\n",current->data);
}

int GoPrevious()
{
    if(current==NULL)
        return 0;

    else if(current->prev==NULL)
    {
        printf("There are no previous webpages to display! \n");
    }
    else
        current=current->prev;

}
int GoNext()
{
    if(current==NULL)
    {
        return 0;
    }
    else if(current->next==NULL)
    {
        printf("There are no web pages to display.Try again!\n");
    }
    else
        current=current->next;
}

int main()
{
    int choice,pageNum,current;
    while(1)
    {
        printf("\nChoose any one of the following option\n");
        printf("    1.Insert a page number   \n");
        printf("    2.Go Next         \n");
        printf("    3.Go Previous  \n");
        printf("    4.DisplayCurrent     \n");
        printf("    5.Display    \n");
        printf("    6.Exit     \n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter a page number:");
                scanf("%d",&pageNum);
                InsertE(pageNum);
                DisplayCurrent();
                display();
                break;

            case 2:
                GoNext();
                DisplayCurrent();
                display();
                break;
            case 3:
                GoPrevious();
                DisplayCurrent();
                display();
                break;
            case 4:
                DisplayCurrent();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Wrong choice ! Try again");

        }
    }
}
