#include<stdio.h>
#include"list.h"
int main()
{
    int value,choice;
    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    PUSH INT                          \n");
        printf ("      2    POP  INT                          \n");
        printf ("      3    DISPLAY  INT                      \n");
        printf ("      4    EXIT                              \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice:");
        scanf    ("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to be pushed:");
            scanf("%d", &value);
            InsertB(value);
            break;
        case 2:
            DeleteB();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice, try again!\n");
        }
    }
}

