#include<stdio.h>
#include<stdlib.h>

int currentSize, maxSize;

struct node
{
        int data;
        struct node* next;
};

struct node *top, *p;

void push()
{
        if(currentSize>=maxSize)
        {
                printf("Stack Overflow.\n\n");
                return;
        }
        else
        {
                int element;
                if(currentSize==0)
                {
                        top=(struct node*)malloc(sizeof(struct node));
                        printf("Enter the element to be pushed: ");
                        scanf("%d", &element);
                        top->data=element;
                        top->next=NULL;
                        printf("Element \'%d\' added to stack.\n\n", element);
                }
                else
                {
                        p=(struct node *)malloc(sizeof(struct node));
                        printf("Enter the element to be pushed: ");
                                scanf("%d", &element);
                        p->data=element;
                        p->next=top;
                        top=p;
                        printf("Element \'%d\' added to stack.\n\n", element);
                }
                currentSize++;
                return;
        }
}

void pop()
{
        if(currentSize<=0)
        {
                printf("Stack Underflow.\n\n");
                return;
        }
        else
        {
                p=top;
                top=top->next;
                printf("Element \'%d\' removed from stack.\n\n", p->data);
                free(p);
                currentSize--;
                return;
        }
}

void peek()
{
        if(currentSize>0)
                printf("Element at the top of stack is \'%d\'.\n\n", top->data);
        else
                printf("Stack is empty.\n\n");
        return;
}

int main()
{
        int mode;
        currentSize=0;
        printf("\nEnter the size of the stack: ");
        scanf("%d", &maxSize);
        printf("\n");
        while(1)
        {
                printf("Enter 1 to push, 2 to pop, 3 to peek, 0 to exit: ");
                scanf("%d", &mode);
                printf("\n");
                switch(mode)
                {
                        case 1: push();
                                break;
                        case 2: pop();
                                break;
                        case 3: peek();
                                break;
                        case 0:
                        default: exit(0);
                                 break;
                }
        }
        return 0;
}
