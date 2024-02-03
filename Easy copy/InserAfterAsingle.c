#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;  
}node;

node *head=NULL;

void createNode(node **head){
    node *p=(node*)malloc(sizeof(node));
    if(p==NULL){
        printf("Memory Error!\n");
        return;
    }
    printf("Enter data:");
    scanf("%d",&(p->data));
    p->next=NULL;
    if(*head==NULL){
        *head=p;
    }
    else{
        node *curr=*head;
        while(curr->next!=NULL) 
            curr=curr->next;
        curr->next=p;
    }
}

void print(node **head){
    node *curr=*head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

void insAfter(node **head){
    int val;
    node *p=(node*)malloc(sizeof(node));
    if(p==NULL){
        printf("Memory Error!\n");
        return;
    }
    printf("Enter data to insert after:");
    scanf("%d",&val);
    printf("Enter data:");
    scanf("%d",&(p->data));
    p->next=NULL;
    if(*head==NULL){
        *head=p;
    }
    else{
        node *curr=*head;
        while(curr->next!=NULL && curr->data!=val) 
            curr=curr->next;
        if(curr!=NULL){
            p->next=curr->next;
            curr->next=p;
        }
        else{
            printf("No such element found in the list.\n");
        }
    }
}

int main(){
    int n,i;
    printf("Enter no. of nodes you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode(&head);
    }
    print(&head);
    insAfter(&head);
    print(&head);
}