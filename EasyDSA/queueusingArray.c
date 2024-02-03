#include <stdio.h>
#include <stdlib.h>
#define N 5
int arr[N], rear = 0,front=0;
void enqueue(int data)
{
    if (rear == N )
    {
        printf("Overflow\n");
        return;
    }
    arr[rear++] = data;
    printf("Pushed element %d\n", data);
}

void dequeue()
{
    if (front==rear)
    {
        printf("Underflow\n");
        return ;
    }
    int d = arr[front++];
    printf("Popped element %d\n", d);
}

void display()
{
    if (front==rear)
    {
        printf("Empty Queue\n");
        return;
    }
    for (int i = front; i < rear; i++)
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