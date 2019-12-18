#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int stack[50];
int i, top=-1;

void push(int c)
{
        top++;
        stack[top]=c;
        return;
}

int pop()
{
        int c=stack[top];
        top--;
        return c;
}

int peek()
{
        return stack[top];
}

int main()
{
        char a[50];
        int x, y, l;
        printf("\nEnter the prefix expression to be evaluated: ");
        gets(a);
        l=strlen(a);
        for(i=l-1; i>=0; i--)
        {
                if(a[i]==')')
                {
                        i--;
                        int p=0, j=0;
                        while(a[i]!='(')
                        {
                                p=p+(a[i]-'0')*pow(10, j);
                                j++;
                                i--;
                        }
                        push(p);
                }
                else if(a[i]>='0'&&a[i]<='9')
                        push(a[i]-'0');
                else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
                {
                        x=pop();
                        y=pop();
                        switch(a[i])
                        {
                                case '+': push(x+y);
                                        break;
                                case '-': push(x-y);
                                        break;
                                case '*': push(x*y);
                                        break;
                                case '/': push(x/y);
                                        break;
                                case '^': push(x^y);
                                        break;
                        }
                }
                else
                {
                        printf("Invalid character \'%c\' encountered at index %d.\n\n", a[i], i);
                        exit(0);
                }
        }
        printf("Result is %d.\n\n", pop());
        return 0;
}
