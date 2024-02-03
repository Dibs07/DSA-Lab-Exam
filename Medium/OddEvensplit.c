#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL, *hp1 = NULL, *hp2 = NULL;

void createNode(node **head)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Memory Error!\n");
        return;
    }
    printf("Enter data:");
    scanf("%d", &(p->data));
    p->next = NULL;
    if (*head == NULL)
    {
        *head = p;
    }
    else
    {
        node *curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = p;
    }
}

void print(node **head)
{
    node *curr = *head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void OddEvenSplit(node **hp1, node **hp2, node **hp)
{
    int x = 1;
    if (*hp == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    node *curr = *hp, *p = *hp1, *q = *hp2;
    while (curr != NULL)
    {
        if (x % 2 == 0)
        {
            if (*hp1 == NULL)
            {
                *hp1 = curr;
                p = *hp1;
            }
            else
            {
                p->next = curr;
                p = p->next;
            }
            // p->next=NULL;
        }
        else
        {
            if (*hp2 == NULL)
            {
                *hp2 = curr;
                q = *hp2;
            }
            else
            {
                q->next = curr;
                q = q->next;
            }
            // q->next=NULL;
        }
        curr = curr->next;
        x++;
    }
    if (*hp1 != NULL)
        p->next = NULL;
    if (*hp2 != NULL)
        q->next = NULL;
    print(&*hp1);
    print(&*hp2);
}

int main()
{
    int n, i;
    printf("Enter no. of nodes you want to enter: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        createNode(&head);
    }
    print(&head);
    OddEvenSplit(&hp1, &hp2, &head);
    
}