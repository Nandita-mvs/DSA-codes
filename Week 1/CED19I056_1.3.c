//To implement sentinel linear search

#include<stdio.h>
int sentinel_linear_search(int arr[], int n, int x)
{
    int lastvalue,i;
    lastvalue=arr[n];
    arr[n]=x;
    i = 0;
	while (arr[i] != x)
		++i;
    arr[n] = lastvalue;
    if(arr[i]== x)
    {
        printf(" The number is present at position %d\n",i+1);
    }
    else
    {
        printf("The number is not present");
    }
}
int main()

{
    int num[100]={0};

    int n=10;
     printf("Enter 10 numbers\n");

    for(int i=0;i<10;i++)
    {
        printf("Enter number %d:",i+1);
        scanf("%d",&num[i]);
    }

    int k;
    printf("The number to be searched:");
    scanf("%d",&k);

    sentinel_linear_search(num, 10, k);

    return 0;
 }
