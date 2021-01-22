#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include"List1.h"

int main()
{
    struct Node* start1 = NULL;
    struct Node* start3 = NULL;
    int num;

    int choice=1;
    printf("Creating List \n");
    while(choice)
    {
        printf("Enter the data:");
        scanf("%d",&num);
        insert(&start1, num);
        printf("Do you want to continue(Type 0 or 1)?:");
        scanf("%d", &choice);
    }



    printf("\n First list is \n");
    display(start1);

    start3 = set(start1);
    bubbleSort(start3);

    printf("\n The set will have the elements \n");
    display(start3);

    return 0;
}
