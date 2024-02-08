#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *lnp = NULL;

void createNode(node **lnp)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("Memory error\n");
        return;
    }
    printf("Enter data:");
    scanf("%d", &p->data);
    if(*lnp==NULL){
        *lnp=p;
        p->next=*lnp;
    }
    else{
        p->next=(*lnp)->next;
        (*lnp)->next=p;
    }
}

void print(node **lnp){
    node *curr=(*lnp)->next;
    while(curr!=*lnp){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("%d\n",curr->data);
}

void josephus(node **lnp){
    int n,k=1;
    printf("Enter the step for josephus ");
    scanf("%d",&n);
    while(*lnp!=(*lnp)->next){
        node *q=*lnp,*p=(*lnp)->next;
        k=1;
        while(k<n){
            q=p;
            p=p->next;
            k++;
        }
        if(p!=*lnp){
            q->next=p->next;
            p->next=NULL;
            free(p);
        }
        else{
            q->next=p->next;
            *lnp=q;
            p->next=NULL;
            free(p);
        }
        print(&*lnp);
    }
}

void josephus2(node **lnp){
    int n,k=1;
    printf("Enter the step for josephus ");
    scanf("%d",&n);
    node *q=*lnp,*p=(*lnp)->next;
    while(*lnp!=(*lnp)->next){
        k=1;
        while(k<n){
            q=p;
            p=p->next;
            k++;
        }
        if(p!=*lnp){
            q->next=p->next;
            p=p->next;
            
        }
        else{
            q->next=p->next;
            *lnp=q;
            p=p->next;
            //free(p);
        }
        print(&*lnp);
    }
}

int main(){
    int n,i;
    printf("Enter no. of nodes you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode(&lnp);
    }
    print(&lnp);
    josephus2(&lnp);
    
}