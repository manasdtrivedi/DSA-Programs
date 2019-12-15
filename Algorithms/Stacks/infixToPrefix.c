#include<stdio.h>
#include<string.h>

char stack[50];
int top=-1;

void push(char c)
{
        top++;
        stack[top]=c;
        return;
}

char pop()
{
        char c=stack[top];
        top--;
        return c;
}

char peek()
{
        return stack[top];
}

int main()
{
        int l, i, j=0, t;
        char a[50];
        printf("\nEnter infix expression: ");
        gets(a);
        l=strlen(a);
        for(i=0; i<l/2; i++)
        {
                t=a[i];
                a[i]=a[l-i-1];
                a[l-i-1]=t;
        }
        for(i=0; i<l; i++)
        {
                if(a[i]=='(')
                        a[i]=')';
                else if(a[i]==')')
                        a[i]='(';
        }
        char b[l];
        for(i=0; i<l; i++)
        {
                if(a[i]=='(')
                        push(a[i]);
                else if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122)||(a[i]>=48&&a[i]<=57))
                {
                        b[j]=a[i];
                        j++;
                }
                else if(a[i]==')')
                {
                        while(top>=0)
                        {
                                if(peek()!='(')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else
                                {
                                        pop();
                                        break;
                                }
                        }
                }
                else if(a[i]=='+')
                {
                        while(top>=0)
                        {
                                char c=peek();
                                if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else if(c=='(')
                                {
                                        push('+');
                                        break;
                                }
                        }
                        if(top==-1)
                                push('+');
                }
                else if(a[i]=='-')
                {
                        while(top>=0)
                        {
                                char c=peek();
                                if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else if(c=='(')
                                {
                                        push('-');
                                        break;
                                }
                        }
                        if(top==-1)
                                push('-');
                }
                else if(a[i]=='*')
                {
                        while(top>=0)
                        {
                                char c=peek();
                                if(c=='*'||c=='/'||c=='^')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else if(c=='+'||c=='-')
                                {
                                        push('*');
                                        break;
                                }
                                else if(c=='(')
                                {
                                        push('*');
                                        break;
                                }
                        }
                        if(top==-1)
                                push('*');
                }
                else if(a[i]=='/')
                {
                        while(top>=0)
                        {
                                char c=peek();
                                if(c=='*'||c=='/'||c=='^')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else if(c=='+'||c=='-')
                                {
                                        push('/');
                                        break;
                                }
                                else if(c=='(');
                                {
                                        push('/');
                                        break;
                                }
                        }
                        if(top==-1)
                                push('/');
                }
                else if(a[i]=='^')
                {
                        while(top>=0)
                        {
                                char c=peek();
                                if(c=='^')
                                {
                                        b[j]=pop();
                                        j++;
                                }
                                else if(c=='+'||c=='-'||c=='*'||c=='/')
                                {
                                        push('^');
                                        break;
                                }
                                else if(c=='(')
                                {
                                        push('^');
                                        break;
                                }
                        }
                        if(top==-1)
                                push('^');
                }
        }
        while(top>=0)
        {
                if(peek()!='(')
                {
                        b[j]=pop();
                        j++;
                }
                else
                        pop();
        }
        l=strlen(b);
        for(i=0; i<l/2; i++)
        {
                t=b[i];
                b[i]=b[l-i-1];
                b[l-i-1]=t;
        }
        printf("The prefix expression is: ");
        puts(b);
        printf("\n");
        return 0;
}
