#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev,*next;
}node;

node *head=NULL;

void createNode(){
    node *p=(node*)malloc(sizeof(node));
    if(p==NULL){
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL){
        head=p;
        p->prev=NULL;
    }
    else{
        node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=p;
        p->prev=curr;
    }
}

void print(){
    node *curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

void Delete(){
    if(head == NULL) {
        printf("Empty\n");
        return;
    }
    printf("Enter the val to be deleted:  ");
    int x;
    scanf("%d",&x);
    node* temp = head;
    if(head->data==x){
        head = head->next;
        temp->next=NULL;
        free(temp);
        return;
    }
    while(temp!=NULL  && temp->data !=x){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found \n");
        return ;
    }
    else{
        temp->prev->next=temp->next;
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        temp->prev=temp->next=NULL;
        free(temp);
    }
}

void main(){
    int n,i;
    printf("Enter no. of nodes you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode();
    }
    print();
    Delete();
    print();
}