#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
};

struct node *head, *p, *q;

void createLinkedList()
{
        int mode, i;
        head=(struct node*)malloc(sizeof(struct node));
        p = head;
        printf("Enter data for node 1: ");
        scanf("%d", &p->data);
        p->next = NULL;
        i = 2;
        while(1)
        {
                printf("Enter 1 to add node, 2 to loop, 3 to stop: ");
                scanf("%d", &mode);
                if(mode == 1)
                {
                        p->next = (struct node*)malloc(sizeof(struct node));
                        p = p->next;
                        printf("Enter data for node %d: ", i);
                        scanf("%d", &p->data);
                        p->next = NULL;
                        i++;
                }
                else if(mode == 2)
                {
                        int a;
                        printf("Enter node to loop back to: ");
                        scanf("%d", &a);
                        q=head;
                        for(i=1; i<a; i++)
                                q=q->next;
                        p->next=q;
                        printf("Linked list generation with loop complete.\n");
                        break;
                }
                else if(mode == 3)
                {
                        printf("Linked list generation complete.\n");
                        break;
                }
                else
                {
                        printf("Invalid mode.\n");
                }
        }
}

int findLoop()
{
        p = head;
        q = head->next;
        while(p != NULL && q != NULL && q->next != NULL)
        {
                if(p == q)
                {
                        printf("Loop exists!\n");
                        return 1;
                }
                else
                        p = p->next;
                        q = q->next->next;
        }
        printf("Loop does not exist.\n");
        return 0;
}

void removeLoop()
{
        struct node* x;
        x = head;
        while(1)
        {
                do
                {
                        if(p->next == x)
                        {
                                p->next = NULL;
                                printf("Loop removed.\n");
                                return;
                        }
                        p = p->next;
                }while(p != q);
                x = x->next;
        }
}

void printLinkedList(struct node* p)
{
        int i = 1;
        while(p != NULL && i < 20)
        {
                printf("%d --> ", p->data);
                p = p->next;
                i++;
        }
        if(i == 20)
        {
                printf("\n");
                return;
        }
        else
                printf("NULL\n");
}

int main()
{
        int a;
        createLinkedList();
        printf("Linked List: ");
        printLinkedList(head);
        printf("Finding loop...\n");
        a = findLoop();
        if(a == 1)
        {
                printf("Enter 1 to remove loop, 0 otherwise: ");
                scanf("%d", &a);
                if(a == 1)
                {
                        printf("Removing loop...\n");
                        removeLoop();
                        printf("Linked List: ");
                        printLinkedList(head);
                }
        }
        return 0;
}
