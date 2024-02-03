#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
struct node *head=NULL;
void push() {
    node *ptr=(node*)malloc(sizeof(node));
    int val;
    printf("Enter the value to be pushed : ");
    scanf("%d",&val);
    if(ptr==NULL){
        printf("Overflow\n");
    }
    ptr->data=val;
    ptr->next=head;
    head=ptr;
    printf("Pushed element is %d",ptr->data);
}

void pop(){
    if(head==NULL){
        printf("Underflow\n");
        return;
    }
    node* temp = head;
    head=head->next;
    printf("Popped element is %d",temp->data);
    free(temp);
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}
int main(){
    int choice, c = 1;
    

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
            push();
            break;
        case 2:
            pop();
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