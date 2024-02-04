#include <stdio.h>
#define s 5

typedef struct stack
{
    int top;
    int x[s];
} stack;

stack s1, s2;

void push(stack *sp, int data)
{
    if (sp->top == s)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        sp->x[sp->top++] = data;
    }
}

int pop(stack *sp)
{
    if (sp->top == 0)
    {
        printf("Underflow\n");
        return -9999;
    }
    else
    {
        return sp->x[--sp->top];
    }
}

void enqueue(int val)
{
    while (s1.top != 0)
    {
        push(&s2, pop(&s1));
    }
    push(&s1, val);
    while (s2.top != 0)
    {
        push(&s1, pop(&s2));
    }
    printf("Element Pushed\n");
}

void dequeue()
{
    int v = pop(&s1);
    if (v == -9999)
        return;
    printf("Popped Element :%d\n", v);
}

void display()
{
    for (int k = 0; k < s1.top; k++)
        printf("%d ", s1.x[k]);
}

int main()
{
    s1.top = 0;
    s2.top = 0;
    int choice, v;
    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop \n3. Display \n");
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &v);
            enqueue(v);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    } while (choice != 4);
}