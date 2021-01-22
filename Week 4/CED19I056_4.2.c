#include<stdio.h>
#define SIZE 5
struct queue
{
    int array[SIZE];
    int rear;
    int front;
    void(*enqueue)(int,struct queue*);
    void(*dequeue)(struct queue*);
    void(*display)(struct queue*);
};

void enqueue(int,struct queue*);
void dequeue(struct queue*);
void display(struct queue*);

int main()
{
    int num,choice;
    struct queue que1;
    que1.rear=-1;
    que1.front=-1;
    que1.enqueue=enqueue;
    que1.dequeue=dequeue;
    que1.display=display;

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
            que1.enqueue(num,&que1);
            break;
        case 2:
            que1.dequeue(&que1);
            break;
        case 3:
            que1.display(&que1);
            break;
        case 4:
            return 0;
        default:
            printf("Wrong choice, try again!\n");
        }
    }
}
void enqueue(int num,struct queue *que)
{
    if(que->rear == SIZE-1)
        printf("OVERFLOW\n");

    else if(que->rear == -1)
    {
        que->front=0;
        que->rear=0;
        que->array[que->rear]=num;
    }
    else
    {
        que->rear=que->rear+1;
        que->array[que->rear]= num;
    }
}
void dequeue(struct queue *que)
{
    if(que->front == -1 || (que->front) > (que->rear))
    {
        printf("UNDERFLOW\n");
    }
    else if(que->front==que->rear)
    {
        que->rear=-1;
        que->front=-1;
    }
    else
    {
        que->front=que->front+1;
    }
}
void display(struct queue *que)
{
    int i;
    if(que->front == -1 || (que->front) > (que->rear))
        printf("QUEUE IS EMPTY\n");
    else
    {
        for(i=que->front;i<=que->rear;i++)
        {
            printf("  %d",que->array[i]);
        }
    printf("\n");
    }

}




