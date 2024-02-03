#include <stdio.h>
#define size 5

typedef struct q
{
    int x[size];
    int rear;
    int front;
} queue;

queue q;

void enqueue(queue *qp)
{
    int v;

    if (qp->rear == size)
    {
        printf("\n.....Overflow.....\n");
        return;
    }

    printf("Enter the value:");
    scanf("%d", &v);

    qp->x[qp->rear++] = v;

    printf("\nElement is pushed\n");
}

int dequeue(queue *qp)
{
    int v;
    if (qp->rear  == qp->front)
    {
        printf("\n.....Underflow.....\n\n");
        return -9999;
    }

    v = qp->x[qp->front++];

    printf("\nPoped element is %d\n", v);
    return v;
}
void display(queue *qp)
{
    if (qp->rear  == qp->front)
    {
        printf("\n.....Empty Queue.....\n\n");
    }
    for(int i=qp->front;i<qp->rear;i++){
        printf("%d\n",qp->x[i]);
    }
}
void main()
{
    int choice, c = 1;
    q.rear = 0;
    q.front = 0;
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