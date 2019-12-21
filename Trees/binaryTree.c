#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* left;
        struct node* right;
};

struct node* root = NULL;

void insert()
{
        struct node* p;
        p = root;
        if(root == NULL)
        {
                root = (struct node*)malloc(sizeof(struct node));
                root->left = NULL;
                root->right = NULL;
                printf("Enter data for the root: ");
                scanf("%d", &root->data);
                return;
        }
        while(1)
        {
                int direction;
                printf("Enter 0 to go left, 1 for right: ");
                scanf("%d", &direction);
                if(direction == 0)
                {
                        if(p->left == NULL)
                        {
                                p->left = (struct node*)malloc(sizeof(struct node));
                                p = p->left;
                                p->left = NULL;
                                p->right = NULL;
                                printf("Enter the data: ");
                                scanf("%d", &p->data);
                                break;
                        }
                        else
                                p = p->left;
                }
                else if(direction == 1)
                {
                        if(p->right == NULL)
                        {
                                p->right = (struct node*)malloc(sizeof(struct node));
                                p = p->right;
                                p->left = NULL;
                                p->right = NULL;
                                printf("Enter the data: ");
                                scanf("%d", &p->data);
                                break;
                        }
                        else
                                p = p->right;
                }
                else
                        printf("Invalid direction.\n");
        }
}

void delete()
{
        if(root == NULL)
        {
                printf("The binary tree is empty. Nothing to be deleted.\n");
                return;
        }
        struct node* p;
        p = root;
        struct node* parentOfp;
        int leftRightOrDelete;
        int directionTakenPreviously = -1;
        while(1)
        {
                printf("Enter 0 to go left, 1 for right, 2 to delete current node: ");
                scanf("%d", &leftRightOrDelete);
                if(leftRightOrDelete == 0)
                {
                        if(p->left != NULL)
                        {
                                parentOfp = p;
                                p = p->left;
                                directionTakenPreviously = 0;
                        }
                        else
                                printf("Current node does not have left child.\n");
                }
                else if(leftRightOrDelete == 1)
                {
                        if(p->right != NULL)
                        {
                                parentOfp = p;
                                p = p->right;
                                directionTakenPreviously = 1;
                        }
                        else
                                printf("Current node does not have right child.\n");
                }
                else if(leftRightOrDelete == 2)
                {
                        if(directionTakenPreviously == 0)
                        {
                                parentOfp->left = NULL;
                                free(p);
                        }
                        else if(directionTakenPreviously == 1)
                        {
                                parentOfp->right = NULL;
                                free(p);
                        }
                        else
                        {
                                root = NULL;
                        }
                        break;
                }
                else
                        printf("Invalid leftRightOrDelete value entered.\n");
        }
}

void preorder(struct node* p)
{
        if(p == NULL)
                return;
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
}

void inorder(struct node* p)
{
        if(p == NULL)
                return;
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
}

void postorder(struct node* p)
{
        if(p == NULL)
                return;
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
}

int main()
{
        int mode;
        while(1)
        {
                printf("Enter 1 to insert node, 2 to delete node, 3 for preorder, 4 for inorder, 5 for postorder, 0 to exit: ");
                scanf("%d", &mode);
                switch(mode)
                {
                        case 1: insert();
                                break;
                        case 2: delete();
                                break;
                        case 3: printf("Preorder Traversal: ");
                                preorder(root);
                                printf("\n");
                                break;
                        case 4: printf("Inorder Traversal: ");
                                inorder(root);
                                printf("\n");
                                break;
                        case 5: printf("Postorder Traversal: ");
                                postorder(root);
                                printf("\n");
                                break;
                        case 0:
                        default: exit(0);
                }
        }
        return 0;
}
