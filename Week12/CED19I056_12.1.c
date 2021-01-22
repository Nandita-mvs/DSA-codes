#include<stdio.h>
#include <stdlib.h>
#define SIZE 20
int size=0;
int array[SIZE]={0};

//Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to heapify the array
void heapify(int array[],int size,int i)
{
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<size && array[left]>array[largest])
        {
            largest=left;
        }
        if(right<size && array[right]>array[largest])
        {
            largest=right;
        }
        if(largest != i)
        {
            swap(&array[i] ,&array[largest]);
            heapify(array,size,largest);
        }
    }
}

//Function to insert a new element into heap
void insert(int array[],int value)
{
    if(size==0)
    {
        array[0]=value;
        size=size+1;
    }
    else
    {
        array[size]=value;
        size=size+1;
        for(int i=(size/2)-1;i>=0;i--)
        {
            heapify(array,size,i);
        }
    }
}

//Function to delete an element from the heap
void delete(int array[],int value)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(value==array[i])
        {
            break;
        }
    }
    swap(&array[i], &array[size-1]);
    size=size-1;
    for(int i=(size/2)-1;i>=0;i--)
    {
        heapify(array,size,i);
    }
}

//Function to sort an array using heapsort
void heapsort(int array[],int size)
{
    int i;
    for(i=size/2-1;i>=0;i--)
    {
        heapify(array,size,i);
    }
    printf("MAX HEAP ARRAY\n");
    print(array,size);

    for(int i=size-1;i>=0;i--)
    {
        swap(&array[0],&array[i]);
        heapify(array,i,0);
    }
}

//Function to diplay the elements in the array
void print(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d  ",array[i]);
    }
    printf("\n");
}

int main()
{
    int value;
    int choice;

    while(1)
    {
        printf ("MAX HEAP\n");
        printf ("------------------------------------------\n");
        printf ("      1    INSERT                         \n");
        printf ("      2    DELETE                         \n");
        printf ("      3    HEAP SORT                      \n");
        printf ("      4    DISPLAY                        \n");
        printf ("      5    EXIT                           \n");
        printf ("------------------------------------------\n");

		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
            case 1:
                printf("Enter the value to insert:");
                scanf("%d",&value);
                insert(array,value);
				print(array,size);
				break;

            case 2:
                printf("Enter the value to delete:");
                scanf("%d",&value);
                delete(array,value);
                print(array,size);
                break;

            case 3:
                printf("Performing Heap sort\n");
                heapsort(array,size);
                printf("Sorted array\n");
                print(array,size);
                break;

            case 4:
                print(array,size);
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong choice!");
		}
    }
}

