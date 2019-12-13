#include<stdio.h>
#include<stdlib.h>

int top, size;

void push(int a[])
{
        if(top>=size-1)
                printf("Stack Overflow.\n");
        else
        {
                int element;
                printf("Enter element to push: ");
                scanf("%d", &element);
                top++;
                a[top]=element;
                printf("Element \'%d\' pushed to stack.\n", element);
        }
}

void pop(int a[])
{
        if(top<0)
                printf("Stack Underflow.\n");
        else
        {
                int element;
                element=a[top];
                top--;
                printf("Element \'%d\' popped from stack.\n", element);
        }
}

void peek(int a[])
{
        if(top<0)
                printf("Stack is empty.\n");
        else
                printf("Element at the top is %d.\n", a[top]);
}

int main()
{
        int mode;
        size=0;
        top=-1;
        printf("Enter size of stack: ");
        scanf("%d", &size);
        int a[size];
        while(1)
        {
                printf("Enter 1 to push, 2 to pop, 3 to peek, 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: push(a);
                                break;
                        case 2: pop(a);
                                break;
                        case 3: peek(a);
                                break;
                        case 0:
                        default: exit(0);
                }
        }
        return 0;
}
