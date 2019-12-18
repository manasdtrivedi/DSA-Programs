#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[50];
int i, j, top=-1;

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
        printf("\nEnter the postfix expression to be evaluated: ");
        gets(a);
        l=strlen(a);
        for(i=0; i<l; i++)
        {
                if(a[i]=='(')
                {
                        i++;
                        int p=0;
                        while(a[i]!=')')
                        {
                                p=p*10+(a[i]-'0');
                                i++;
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
                                case '+': push(y+x);
                                        break;
                                case '-': push(y-x);
                                        break;
                                case '*': push(y*x);
                                        break;
                                case '/': push(y/x);
                                        break;
                                case '^': push(y^x);
                                        break;
                        }
                }
                else
                {
                        printf("Invalid character %c encountered in postfix expression.\n\n", a[i]);
                        exit(0);
                }
        }
        printf("Result is %d.\n\n", pop());
        return 0;
}
