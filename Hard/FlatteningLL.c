#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *child;
} node;

node *head = NULL;

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    p->child = NULL;
    return p;
}
void print(node **head)
{
    node *curr = *head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->child;
    }
}

void flattening(node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    node *p = *head;
    while (p->next != NULL)
    {
        node *q = p->next, *r = p, *a = createNode(-1);
        a->next = p->next->next;
        p = a;

        while (r != NULL && q != NULL)
        {
            if (r->data < q->data)
            {
                a->child = r;
                r = r->child;
            }
            else
            {
                a->child = q;
                q = q->child;
            }
            a = a->child;
            a->next = NULL;
            
        }

        if (r != NULL)
        {
             a->child = r;
        }
        if (q != NULL)
        {
            a->child = q;
        }
    }
    while (p->data == -1)
    {
        p = p->child;
    }
    *head = p;
}

int main()
{
    node *hp = createNode(3);
    head = hp;
    hp->next = createNode(2);
    hp->next->child = createNode(10);
    hp->next->next = createNode(1);
    hp->next->next->child = createNode(7);
    hp->next->next->child->child = createNode(11);
    hp->next->next->child->child->child = createNode(12);
    // hp->next->next->child->child->child = createNode(13);
    hp->next->next->next = createNode(4);
    hp->next->next->next->child = createNode(9);
    hp->next->next->next->next = createNode(5);
    hp->next->next->next->next->child = createNode(6);
    hp->next->next->next->next->child->child = createNode(8);
    // 3->2->1->4->5
    //    |  |  |  |
    //    10 7  9  6
    //       |     |
    //       11    8
    //       |
    //       12
    // 2->3->10
    // 1->2->3->7->10->11->12
    // 1->2->3->4->5->6->7->8->9->10->11->12
    flattening(&head);
    print(&head);
}