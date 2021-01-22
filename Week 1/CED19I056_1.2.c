//to implement linear search

#include<stdio.h>

void search(int arr[], int n, int x)
{
    int i, count=0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            {
                printf(" The number is present at position %d\n",i+1);
                count++;
            }
    }
    if(count==0)
        printf("The number entered is not present");
    return ;

}

int main()
{
    int num[100]={0};
    int n=10;
     printf("Enter 10 numbers\n");
    for(int i=0;i<10;i++)
    {
        printf("Enter the number %d:",i+1);
        scanf("%d",&num[i]);
    }
    int k;
    printf("The number to be searched:");
    scanf("%d",&k);

    search(num, 10, k);

    return 0;
}

