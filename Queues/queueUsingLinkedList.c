#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
};

struct node* head = NULL;
int maxSize, size = 0;

void enqueue()
{
        if(head == NULL)
        {
                head = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data: ");
                scanf("%d", &head->data);
                head->next = NULL;
                size++;
        }
        else
        {
                if(size<maxSize)
                {
                        struct node *p;
                        p = head;
                        while(p->next != NULL)
                                p = p->next;
                        struct node *q;
                        q = (struct node*)malloc(sizeof(struct node));
                        p->next = q;
                        printf("Enter the data: ");
                        scanf("%d", &q->data);
                        q->next = NULL;
                        size++;
                }
                else
                        printf("Queue is full.\n");
        }
}

void dequeue()
{
        if(head == NULL)
                printf("Queue is empty.\n");
        else if(head->next == NULL)
        {
                printf("%d is dequeued.\n", head->data);
                struct node* p;
                p = head;
                head=NULL;
                free(p);
                size--;
        }
        else
        {
                printf("%d is dequeued.\n", head->data);
                struct node* p;
                p = head;
                head = head->next;
                free(p);
                size--;
        }
}

void display()
{
        if(head == NULL)
                printf("Queue is empty.\n");
        else
        {
                struct node *p;
                p = head;
                do
                {
                        printf("%d ", p->data);
                        p = p->next;
                }while(p != NULL);
                printf("\n");
        }
}

int main()
{
        int mode=0;
        printf("Enter maximum size of queue: ");
        scanf("%d", &maxSize);
        while(1)
        {
                printf("Enter 1 to enqueue, 2 to dequeue, 3 to display queue, 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: enqueue();
                                break;
                        case 2: dequeue();
                                break;
                        case 3: display();
                                break;
                        case 0:
                        default: exit(0);
                                break;
                }
        }
        return 0;
}
