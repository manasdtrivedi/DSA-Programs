#include<stdio.h>
#include<stdlib.h>

int size, front=-1, rear=-1;

void enqueue(int q[])
{
        if((rear==size-1&&front==0)||(rear==front-1))
                printf("Queue is full.\n");
        else if(rear==size-1&&front!=0)
        {
                rear=0;
                printf("Enter the data: ");
                scanf("%d", &q[rear]);
        }
        else
        {
                if(front==-1)
                        front++;
                rear++;
                printf("Enter the data: ");
                scanf("%d", &q[rear]);
        }
        return;
}

void dequeue(int q[])
{
        if(front==-1)
                printf("Queue is empty.\n");
        else if(front==rear)
        {
                printf("%d is dequeued.\n", q[front]);
                front=-1;
                rear=-1;
        }
        else if(front==size-1)
        {
                printf("%d is dequeued.\n", q[front]);
                front=0;
        }
        else
        {
                printf("%d is dequeued.\n", q[front]);
                front++;
        }
        return;
}

void display(int q[])
{
        int i;
        if(front==-1)
                printf("Queue is empty.\n");
        else if(front<=rear)
        {
                for(i=front; i<=rear; i++)
                        printf("%d ", q[i]);
                printf("\n");
        }
        else
        {
                for(i=front; i<size; i++)
                        printf("%d ", q[i]);
                for(i=0; i<=rear; i++)
                        printf("%d ", q[i]);
                printf("\n");
        }
        return;
}

int main()
{
        int mode=0;
        printf("Enter the size of queue: ");
        scanf("%d", &size);
        int queue[size];
        while(1)
        {
                printf("Enter 1 to enqueue, 2 to dequeue, 3 to display, 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: enqueue(queue);
                                break;
                        case 2: dequeue(queue);
                                break;
                        case 3: display(queue);
                                break;
                        case 0:
                        default: exit(0);
                                break;
                }
        }
        return 0;
}
