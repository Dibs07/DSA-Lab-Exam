#include <stdio.h>
#include <stdlib.h>
#define N 5
int arr[N], top = 0;
void push(int data)
{
    if (top == N)
    {
        printf("Overflow\n");
        return;
    }
    arr[top++] = data;
    printf("Pushed element %d\n", data);
}

void dequeue()
{
    if (top == 0)
    {
        printf("Underflow\n");
        return;
    }
    int d = arr[--top];
    printf("Popped element %d\n", d);
}

void display()
{
    if (top == 0)
    {
        printf("Empty Stack\n");
        return;
    }
    for (int i = 0; i < top; i++)
    {
        printf("%d", arr[i]);
    }
}

int main()
{
    int choice, v;
    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop \n3. Display \n4");
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &v);
            push(v);
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