#include <stdio.h>
#define size 6

typedef struct Queue
{
    int x[size];
    int rear1, front1, rear2, front2;
} queue;

queue q;

void enqueue(queue *q)
{
    if (q->rear1 > q->rear2)
    {
        printf("Overflow\n");
        return;
    }
    int c;
    printf("Press 1 to enqueue from down\n");
    printf("Press 0 to enqueue from up\n");
    scanf("%d", &c);
    if (c == 1)
    {
        printf("\nEnter the element you want to add at the bottom : ");
        scanf("%d", &q->x[q->rear1++]);
    }
    if (c == 0)
    {
        printf("\nEnter the element you want to add at the top: ");
        scanf("%d", &q->x[q->rear2--]);
    }
    printf("Element enqueued");
}

void dequeue(queue *q)
{
    int c;
    printf("Press 1 to dequeue from down\n");
    printf("Press 0 to dequeue from up\n");
    scanf("%d", &c);
    if (c == 1 && q->rear1 == q->front1 || q->rear2 == q->front2 && c == 0)
    {
        printf("Underflow \n");
        return;
    }
    if (c == 1)
    {
        printf("\nDequed element from bottom: %d ", q->x[q->front1]);
        q->front1++;
    }
    if (c == 0)
    {
        printf("\nDequed element from up: %d ", q->x[q->front2]);
        q->front2--;
    }
}

void display(queue *q)
{
    printf("Elements in the queue are : \n");
    for(int i=q->front1;i<q->rear1;i++)
        printf("%d ",q->x[i]);
    printf("\n");
    for(int i=q->rear2+1;i<=q->front2;i++)
        printf("%d ",q->x[i]);
}

void main()
{
    int choice, c = 1;
    q.rear1 = 0;
    q.front1 = 0;
    q.rear2 = size - 1;
    q.front2 = size - 1;
    do
    {
        printf("Enter 1 for enqueue element into queue\n");
        printf("Enter 2 for dequeue element from queue\n");
        printf("Enter 3 for exit\n");
        printf("Enter 4 for display\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            return;
        case 4:
            display(&q);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
}