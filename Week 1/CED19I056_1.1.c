//To implement deleting,inserting at a given position in a given array

#include<stdio.h>
int main()
{
    int ranklist[100]={0};
    int senario;
    int classstrength;

    printf("Enter the no of students in the class:");
    scanf("%d",&classstrength);

    for(int i=0;i<classstrength;i++)
    {
          printf("Roll-no of rank %d student:",i+1);
          scanf("%d",&ranklist[i]);
    }

    printf("Enter the SENARIO number you want to choose:(1,2,3,4)");
    scanf("%d",&senario);

    if(senario==1)
        senario1(ranklist,classstrength);
    else if(senario==2)
        senario2(ranklist,classstrength);
    else if(senario==3)
        senario3(ranklist,classstrength);
    else
        senario4(ranklist,classstrength);

    return 0;
}
//A new student who has joined in a class, and he/she scored 3rd rank and you want to insert at index 2
int senario1(int ranklist[],int classstrength)

{
    printf("SENARIO 1\n");

    int newrollno;
    int rank=3;

    printf("What is the Roll-no of the new student: ");
    scanf("%d",&newrollno);

    for(int i = classstrength; i >= rank; i--)
        ranklist[i] = ranklist[i - 1];

         ranklist[rank - 1] = newrollno;

    classstrength=classstrength+1;

    printf("The new rank-list is:");
    for (int i = 0; i < classstrength; i++)
        printf("%d ", ranklist[i]);

    printf("\n");

    return 0;
}

// A student whose rank is 1 has moved to another clas
int senario2(int ranklist[],int classstrength)

{
     printf("SENARIO 2\n");

    int rank=1;

    for(int i=rank-1; i<classstrength-1; i++)
        ranklist[i] = ranklist[i + 1];
    classstrength--;

    printf("The new rank-list is:");

    for(int i=0; i < classstrength; i++)
        printf("%d ", ranklist[i]);

    printf("\n");

    return 0;

}

// A student whose rank is 'm' has moved to another class
int senario3(int ranklist[],int classstrength)
{
    printf("SENARIO 3\n");

    int rank;

    printf("Enter the rank of the student who has moved:");
    scanf("%d",&rank);

      if(rank<0 || rank>classstrength)
    {
        printf("Invalid position! Please enter position between 1 to %d",classstrength);
    }
      else
    {
        for(int i=rank-1; i<classstrength-1; i++)
            ranklist[i] = ranklist[i + 1];
        classstrength--;

        printf("The new rank-list is:");

        for(int i=0; i < classstrength; i++)
        printf("%d ", ranklist[i]);

        printf("\n");

    }

    return 0;
}

//A new student who has joined in a class, and he/she scored kth rank and you want to insert at index k-1
int senario4(int ranklist[],int classstrength)
{
    printf("SENARIO 4\n");

    int newrollno;
    int rank;

    printf("What is the Roll-no of the new student: ");
    scanf("%d",&newrollno);

    printf("Enter the rank of the new student:");
    scanf("%d",&rank);

    for(int i = classstrength; i >= rank; i--)
        ranklist[i] = ranklist[i - 1];

         ranklist[rank - 1] = newrollno;

    classstrength=classstrength+1;
    printf("The new rank-list is:");
    for (int i = 0; i < classstrength; i++)
        printf("%d ", ranklist[i]);

    printf("\n");

    return 0;
}

