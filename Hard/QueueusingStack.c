#include <stdio.h>
#define s 5

int s1[s], s2[s], i = 0, j = 0;

void enqueue(int val)
{
    if (i == s)
    {
        printf("Overflow\n");
        return;
    }
    else{
        while(i!=0){
            s2[j++]=s1[--i];
        }
        s1[i++] = val;
        while(j!=0){
            s1[i++]=s2[--j];
        }
        printf("Element Pushed\n");
    }
}

void dequeue()
{
    if (i==0)
    {
        printf("Underflow\n");
        return ;
    }
    else{
        int v=s1[--i];
        printf("Popped Element :%d\n",v);
    }
}

void display(){
    for(int k=0;k<i;k++)
        printf("%d ",s1[k]);
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