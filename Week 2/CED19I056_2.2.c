#include<stdio.h>
#include "sort.h"

int binarysearch(int array[],int key,int n)
{
    int l=0;
    int r=n-1;
    int m;


    while(l<=r)
    {   m=(l+r)/2;

        if(array[m]==key)
        {
           return(m);
           break;
        }
        else if(array[m] < key)
        {
            l=m+1;
        }
        else if(array[m] > key)
        {
            r=m-1;
        }
    }
    if (l > r)
      return -1;
}
int main()
{
    int array[100]={0};
    int key;
    int n,position;

    printf("How many numbers are you going to enter:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the number %d:",i+1);
        scanf("%d",&array[i]);
    }


    selectionsort(array,n);
    printArray(array,n);

    printf("Enter the number you want to search for:");
    scanf("%d",&key);

    int index= binarysearch(array,key,n);
    if(index != -1)
        printf("SEARCH SUCCESSFUL ! ");
        if(index==-1)
        printf("SEARCH FAILED ! The element is not present in the list");

    return 0;
}


