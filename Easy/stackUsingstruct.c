#include <stdio.h>
#define size 10


typedef struct stack
{
    int x[size];
    int top;
} stack;

stack s;

void push(stack *sp)
{
    int v;
    if (sp->top == size)
    {
        printf("\n.....Overflow.....\n");
        return;
    }
    printf("Enter the value:");
    scanf("%d", &v);

    sp->x[sp->top++] = v;

    printf("\nElement is pushed\n\n");
}

void pop(stack *sp)
{
    int v;
    if (sp->top < 1)
    {
        printf("\n.....Underflow.....\n\n");
        return;
    }

    v = sp->x[--sp->top];

    printf("\nPoped element is %d\n\n", v);
    
}

void display(stack *sp)
{
    if (sp->top < 1)
    {
        printf("\n.....Underflow.....\n\n");
        return;
    }
    for (int i = 0; i < sp->top; i++)
    {
        printf("Data %d is %d\n", i + 1, sp->x[i]);
    }
    printf("\n");
}

void main()
{
    int choice, c = 1;
    s.top = 0;

    do
    {
        printf("Enter 1 for push element into stack\n");
        printf("Enter 2 for pop element from stack\n");
        printf("Enter 3 for exit\n");
        printf("Enter 4 for display\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            return;
        case 4:
            display(&s);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
}