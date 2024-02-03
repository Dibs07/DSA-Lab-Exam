#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
struct node *head = NULL;
void enqueue()
{
    node *ptr = (node *)malloc(sizeof(node));
    int val;
    printf("Enter the value to be pushed : ");
    scanf("%d", &val);
    if (ptr == NULL)
    {
        printf("Overflow\n");
    }
    ptr->data = val;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next=NULL;
    }
    printf("Pushed element is %d\n", ptr->data);
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    node *temp = head;
    head = head->next;
    printf("Popped element is %d\n", temp->data);
    free(temp);
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void main()
{
    int choice, c = 1;
    do
    {
        printf("Enter 1 for enqueue element into stack\n");
        printf("Enter 2 for dequeue element from stack\n");
        printf("Enter 3 for exit\n");
        printf("Enter 4 for display\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return;
        case 4:
            display();
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
}