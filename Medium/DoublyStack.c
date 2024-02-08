#include <stdio.h>
#define size 6

typedef struct Stack
{
    int x[size];
    int topA, topB;
} stack;

stack s;

void push(stack *s)
{
    if (s->topA > s->topB)
    {
        printf("Overflow\n");
        return;
    }
    int c;
    printf("Press 1 to push from down\n");
    printf("Press 0 to push from up\n");
    scanf("%d", &c);
    if (c == 1)
    {
        printf("\nEnter the element you want to add at the bottom : ");
        scanf("%d", &s->x[s->topA++]);
    }
    if (c == 0)
    {
        printf("\nEnter the element you want to add at the top: ");
        scanf("%d", &s->x[s->topB--]);
    }
    printf("Element Pushed\n");
}

void pop(stack *s)
{
    int c;
    printf("Press 1 to pop from down\n");
    printf("Press 0 to pop from up\n");
    scanf("%d", &c);
    if ((c == 1 && s->topA == 0) || (c == 0 && s->topB == size - 1))
    {
        printf("Underflow \n");
        return;
    }
    if (c == 1)
    {
        printf("\nPopped element from bottom: %d ", s->x[--s->topA]);
    }
    if (c == 0)
    {
        printf("\nPopped element from up: %d ", s->x[++s->topB]);
    }
}

void display(stack *s)
{
    printf("Elements in the stack are : \n");
    for (int i = 0; i < s->topA; i++)
        printf("%d ", s->x[i]);
    printf("\n");
    for (int i = size - 1; i > s->topB; i--)
        printf("%d ", s->x[i]);
}

int main()
{
    int choice;
    s.topA = 0;
    s.topB = size - 1;
    do
    {
        printf("\nEnter 1 for push element into stack\n");
        printf("Enter 2 for pop element from stack\n");
        printf("Enter 3 for exit\n");
        printf("Enter 4 for display\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            return 0;
        case 4:
            display(&s);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
}
