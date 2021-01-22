#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include"List1.h"

int main()
{

    struct Node* start1 = NULL;
    struct Node* start2 = NULL;

    struct Node* start3 = NULL;
    int num;

    int choice1=1;
    int choice2=1;

    printf("Creating List 1\n");
    while(choice1)
    {
        printf("Enter the data:");
        scanf("%d",&num);
        insert(&start1, num);
        printf("Do you want to continue(Type 0 or 1)?:");
        scanf("%d", &choice1);
    }

    printf("Creating List 2\n");
    while(choice2)
    {
        printf("Enter the data:");
        scanf("%d",&num);
        insert(&start2, num);
        printf("Do you want to continue(Type 0 or 1)?:");
        scanf("%d", &choice2);
    }
    start3 = Union(start1, start2);

    printf("\n First list is \n");
    display(start1);

    printf("\n Second list is \n");
    display(start2);

    bubbleSort(start3);

    printf("\n Union list is \n");
    display(start3);

    return 0;
}
