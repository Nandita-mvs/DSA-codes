#include<stdio.h>
#include"list.h"
int main()
{
    int num,choice;

    printf ("QUEUE OPERATION\n");
    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    ENQUEUE                          \n");
        printf ("      2    DEQUEUE                          \n");
        printf ("      3    DISPLAY                       \n");
        printf ("      4    EXIT                              \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice:");
        scanf    ("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to be enqueued:");
            scanf("%d", &num);
            InsertE(num);
            break;
        case 2:
            DeleteB();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Wrong choice, try again!\n");
        }
    }
}
