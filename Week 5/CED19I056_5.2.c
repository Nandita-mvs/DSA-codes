#include<stdio.h>
#include"Cqueue.h"
void sheduling(int [],int,int) ;

int main()
{

    Cque1.rear=-1;
    Cque1.front=-1;
    Cque1.enqueue=enqueue;
    Cque1.dequeue=dequeue;
    Cque1.display=display;

    int num,share_time,i;
    int array[SIZE]={0};
    printf("No. of processes:");
    scanf("%d",&num);

    printf("Time required for each process\n");
    for(i=0;i<=num-1;i++)
    {
        printf("P%d :",i+1);
        scanf("%d",&array[i-1]);
        Cque1.enqueue(array[i-1],&Cque1);
    }

    printf("CPU share time:");
    scanf("%d",&share_time);
    sheduling(array,share_time,num);
    return 0;
}
void sheduling(int array[],int share_time,int num)
{
    int i;
    printf("The CPU queue after enqueuing all the process\n");
    Cque1.display(&Cque1);

    for(i=0;i<100;i++)
    {
        int x;
        printf("SWITCH %d\n",i+1);
        printf("%d Dequeued\n",x =Cque1.dequeue(&Cque1));
       {
           if(x-share_time==0)
            {
              printf("%d units executed\n",x);
              printf("0 is not enqueued and that process is completed\n");
            }
             else if(share_time < x)
            {
                printf("%d units executed\n",share_time);
                Cque1.enqueue(x-share_time,&Cque1);
                printf("Enqueue %d\n",x-share_time);
            }
            else if(share_time==x)
            {
                printf("%d units executed\n",share_time);
                printf("0 is not enqueued and that process is completed\n");

            }
            else if(share_time > x)
            {
                printf("%d units executed\n",x);
                printf("0 is not enqueued and that process is completed\n");
            }
       }
       {
           if(Cque1.rear==-1 && Cque1.front==-1)
            {
                printf("All Process Completed\n");
                printf("\n");
                break;
            }
            else
            {
                printf("Remaining");
                Cque1.display(&Cque1);
            }
       }
        printf("\n");
    }
        printf("CPU Returning to Idle State. Stopping Program.\n");
}














