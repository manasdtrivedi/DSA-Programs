#include<stdio.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char c)
{
        if(top<50)
        {
                top++;
                stack[top]=c;
        }
        else
                printf("Stack Overflow.\n");
        return;
}

char pop()
{
        if(top>=0)
        {
                char c=stack[top];
                top--;
                return c;
        }
        else
        {
                printf("Stack Underflow.\n");
        }
}


int main()
{
        int l, i;
        char a[100];
        printf("\nEnter the string: ");
        gets(a);
        l=strlen(a);
        for(i=0; i<l/2; i++)
                push(a[i]);
        if(l%2)
                i++;
        for(; i<l; i++)
        {
                if(a[i]!=pop())
                        break;
        }
        if(i==l)
                printf("Palindrome.\n\n");
        else
                printf("Not a palindrome.\n\n");
        return 0;
}
