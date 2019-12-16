#include<stdio.h>
#include<string.h>

char tempForPop[25];
char s[25][25];
int top=-1;

void push(char a[])
{
        top++;
        strcpy(s[top], a);
        return;
}

char* pop()
{
        strcpy(tempForPop, s[top]);
        top--;
        return tempForPop;
}

int main()
{
        int l, i;
        char a[50];
        char temp[25], temp1[25], temp2[25];
        printf("\nEnter the postfix expression: ");
        gets(a);
        l=strlen(a);
        for(i=0; i<l; i++)
        {
                if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122)||(a[i]>=48&&a[i]<=57))
                {
                        temp[0]=a[i];
                        temp[1]='\0';
                        push(temp);
                }
                else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
                {
                        temp[0]=a[i];
                        temp[1]='\0';
                        strcpy(temp1, pop());
                        strcpy(temp2, pop());

                        push(strcat(temp, strcat(temp2, temp1)));
                }
        }
        printf("Prefix expression is: %s\n\n", s[0]);
        return 0;
}
