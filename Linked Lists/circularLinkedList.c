#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
};
struct node *head;

void insertNode()
{
        if(head == NULL)
        {
                head = (struct node*)malloc(sizeof(struct node));
                printf("Enter data for head node: ");
                scanf("%d", &head->data);
                head->next = head;
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
                        p->next=head;
                        struct node* q;
                        q = head;
                        while(q->next != head)
                                q = q->next;
                        q->next = p;
                        head = p;
                        return;
                }
                else
                {
                        p = head;
                        for(i = 1; i < position - 1; i++)
                                p = p->next;
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
                printf("Circular linked list is empty.\n");
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
                        if(head->next == head)
                                free(head);
                        else
                        {
                                p = head;
                                while(p->next != head)
                                        p = p->next;
                                struct node* q;
                                q = p->next;
                                p->next = p->next->next;
                                head = p->next;
                                free(q);
                                return;
                        }
                }
                else
                {
                        p = head;
                        for(i = 1; i < position - 1; i++)
                                p = p->next;
                        struct node* q;
                        q = p->next;
                        p->next = p->next->next;
                        free(q);
                        return;
                }
        }
}

void printCircularLinkedList(struct node* p)
{
        printf("%d --> ", p->data);
        if(p->next == head)
                printf("%d\n", head->data);
        else
                printCircularLinkedList(p->next);
}

int main()
{
        int mode;
        while(1)
        {
                printf("Enter 1 to insert a node, 2 to delete a node, 3 to print the circular linked list, 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: insertNode();
                                break;
                        case 2: deleteNode();
                                break;
                        case 3: printCircularLinkedList(head);
                                break;
                        case 0:
                        default: exit(0);
                }
        }
        return 0;
}
