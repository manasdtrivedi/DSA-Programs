#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

struct node* head;

void insertNode()
{
        if(head==NULL)
        {
                head = (struct node*)malloc(sizeof(struct node));
                printf("Enter data for head node: ");
                scanf("%d", &head->data);
                head->next = NULL;
                return;
        }
        else
        {
                int position, i;
                printf("Enter position of node to be inserted: ");
                scanf("%d", &position);
                struct node* p;
                if(position <= 0)
                {
                        printf("Invalid position.\n");
                        return;
                }
                else if(position == 1)
                {
                        p = (struct node*)malloc(sizeof(struct node));
                        printf("Enter the data for this node: ");
                        scanf("%d", &p->data);
                        p->next = head;
                        head = p;
                        return;
                }
                else
                {
                        p = head;
                        for(i = 1; i < position - 1; i++)
                        {
                                if(p->next == NULL)
                                {
                                        printf("There are only %d nodes in the linked list.\n", i);
                                        return;
                                }
                                p = p->next;
                        }
                        struct node* q;
                        q = (struct node*)malloc(sizeof(struct node));
                        printf("Enter the data for this node: ");
                        scanf("%d", &q->data);
                        q->next = p->next;
                        p->next = q;
                        return;
                }
        }
}

void deleteNode()
{
        if(head == NULL)
        {
                printf("Linked list is empty.\n");
                return;
        }
        else
        {
                int position, i;
                printf("Enter position of node to be deleted: ");
                scanf("%d", &position);
                struct node* p;
                if(position <= 0)
                {
                        printf("Invalid position.\n");
                        return;
                }
                else if(position == 1)
                {
                        p = head;
                        head = head->next;
                        free(p);
                        return;
                }
                else
                {
                        p = head;
                        for(i = 1; i < position - 1; i++)
                        {
                                if(p->next == NULL)
                                {
                                        printf("There is no node at specified position.\n");
                                        return;
                                }
                                p = p->next;
                        }
                        if(p->next == NULL)
                        {
                                printf("There is no node at specified position.\n");
                                return;
                        }
                        struct node* q;
                        q = p->next;
                        p->next = p->next->next;
                        free(q);
                        return;
                }
        }
}

void printLinkedList(struct node* p)
{
        if(p != NULL)
        {
                printf("%d --> ", p->data);
                printLinkedList(p->next);
        }
        else
        {
                printf("NULL\n");
                return;
        }
}

int main()
{
        int mode;
        while(1)
        {
                printf("Enter 1 to insert node, enter 2 to delete node, enter 3 to print the linked list, enter 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: insertNode();
                                break;
                        case 2: deleteNode();
                                break;
                        case 3: printLinkedList(head);
                                break;
                        case 0:
                        default: exit(0);
                }
        }
        return 0;
}
