//Program to implement Breadth first search algorithm
#include<stdio.h>
#define SIZE 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[SIZE][SIZE]={0};
int state[SIZE];

void createGraph();
void BFT();
void BFS(int );

void DFT();
void DFS(int );

struct queue
{
    int array[SIZE];
    int rear;
    int front;
    void(*enqueue)(int,struct queue*);
    int(*dequeue)(struct queue*);
    void(*display)(struct queue*);
};

struct stack
{
    int top;
    int arrayStack[SIZE];
    void(*push)(int,struct stack*);
    int(*pop)(struct stack*);
    void(*display)(struct stack*);
};

struct stack stk;
void push(int,struct stack*);
int pop(struct stack*);
void displayStack(struct stack*);

struct queue que;
void enqueue(int,struct queue*);
int dequeue(struct queue*);
void display(struct queue*);

int main()
{
    int num,choice;

    que.rear=-1;
    que.front=-1;
    que.enqueue=enqueue;
    que.dequeue=dequeue;

    stk.push=push;
    stk.pop=pop;
    stk.top=-1;

    createGraph();
    printf("Enter the type of traversal\n 1)Breadth-First traversal\n2)Depth-First Search\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        BFT();
    }
    else
    {
        DFT();
    }
}

void createGraph()
{
    int i;
    int maxEdges;
    int origin=0;
    int desti=0;

    printf("Enter the number of vertices\n");
    scanf("%d",&n);

    maxEdges=n*(n-1);

    printf("Enter the Adajency matrix\n");
    for(i=1;i<maxEdges;i++)
    {
        printf("Enter the %d edge (-1 -1 to quit)\n",i);
        scanf("%d%d",&origin,&desti);

        if(origin==-1||desti==-1)
        {
            break;
        }
        else if(origin > n || desti > n || origin < 0 || desti < 0 )
        {
            printf("This is an invalid entry");
        }
        else
        {
            adj[origin][desti]=1;
        }
    }
}

void BFT()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
    }
    printf("Enter the starting vertex\n");
    scanf("%d",&v);
    BFS(v);
}

void BFS(int v)
{
    int i;

    enqueue(v,&que);
    state[v]=waiting;

    printf("Breadth first search is:");
    while(!isEmptyQueue(&que))
    {
        v=que.dequeue(&que);
        state[v]=visited;
        printf("%d->",v);

        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                que.enqueue(i,&que);
                state[i]=waiting;
           }
        }
    }
}
void DFT()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
    }
    printf("Enter the starting vertex\n");
    scanf("%d",&v);
    DFS(v);
}
void DFS(int v)
{
    int i;
    push(v,&stk);
    while(!isEmptyStack(&stk))
    {
        v=pop(&stk);

        printf("Depth first search is:");
        if(state[v]==initial)
        {
            printf("%d->",v);
            state[v]=visited;
        }
        for(i=n-1;i>=0;i--)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                push(i,&stk);
            }
        }
    }
}

void push(int num,struct stack *sta)
{
    if(sta->top == SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arrayStack[sta->top]=num;
    }
}

int pop(struct stack *sta)
{
    int val;
    if(sta->top==-1)
    {
        printf("The stack is empty\n");
        return -1;
    }
    else
    {
        val=sta->arrayStack[sta->top];
        sta->top=sta->top - 1;
        return val;
    }
}

int isEmptyStack(struct stack *sta)
{
    if(sta->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
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

int isEmptyQueue(struct queue *que)
{
    if(que->front==-1||(que->front > que->rear))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct queue *que)
{
    int val;
    if(que->front == -1 || (que->front) > (que->rear))
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else if(que->front==que->rear)
    {
        val=que->array[que->front];
        que->rear=-1;
        que->front=-1;
        return val;
    }
    else
    {   
        val=que->array[que->front];
        que->front=que->front+1;
        return val;
    }
}

