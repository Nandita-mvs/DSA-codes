#include<stdio.h>
#define SIZE 7
struct Cqueue
{
    int array[SIZE];
    int rear;
    int front;
    void(*enqueue)(int,struct Cqueue*);
    void(*dequeue)(struct Cqueue*);
    void(*display)(struct Cqueue*);
};
void enqueue(int,struct Cqueue*);
void dequeue(struct Cqueue*);
void display(struct Cqueue*);

int main()
{
    int num,choice;
    struct Cqueue Cque1;
    Cque1.rear=-1;
    Cque1.front=-1;
    Cque1.enqueue=enqueue;
    Cque1.dequeue=dequeue;
    Cque1.display=display;

    printf ("CIRCULAR QUEUE OPERATION\n");
    while (1)
    {
        printf ("------------------------------------------\n");
        printf ("      1    ENQUEUE                          \n");
        printf ("      2    DEQUEUE                          \n");
        printf ("      3    DISPLAY                       \n");
        printf ("      4    EXIT                              \n");
        printf ("------------------------------------------\n");

        printf ("Enter your choice:");
        scanf  ("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number to be enqueued:");
            scanf("%d",&num);
            Cque1.enqueue(num,&Cque1);
            break;
        case 2:
            Cque1.dequeue(&Cque1);
            break;
        case 3:
            Cque1.display(&Cque1);
            break;
        case 4:
            return 0;
        default:
            printf("Wrong choice, try again!\n");
        }
    }
}

void enqueue(int num,struct Cqueue *que)
{
    if((que->front==0 && que->rear==SIZE-1) || (que->rear == que->front -1))
        printf("OVERFLOW\n");

    else if(que->front==-1)
    {
        que->front=que->rear=0;
        que->array[que->rear]=num;
    }

    else if(que->rear==SIZE-1 && que->front != 0)
    {
        que->rear=0;
        que->array[que->rear]=num;
    }

    else
    {
        que->rear=(que->rear+1);
        que->array[que->rear]=num;
    }

}
void dequeue(struct Cqueue *que)
{
    if(que->front == -1 && que->rear==-1)
        printf("UNDERFLOW\n");
    if(que->front == que->rear)
        que->front=que->rear=-1;
    else
    {
      if(que->front==SIZE-1)
            que->front=0;
      else
        que->front=(que->front+1);
    }
}
void display(struct Cqueue *que)
{
    int i;

    if(que->front==-1 && que->rear==-1)
        printf("QUEUE IS EMPTY\n");
    else
    {
        if((que->front) <= (que->rear))
        {
            for(i=que->front; i<=que->rear; i++)
            {
                printf("    %d",que->array[i]);
            }
        }
        else
        {
            for(i=que->front;i<SIZE;i++)
                printf("    %d",que->array[i]);
            for(i=0;i<=que->rear;i++)
                printf("    %d",que->array[i]);
        }
    }
    printf("\n");
}















