#include<stdio.h>
int n;
void printArray(int arr[]){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void positionDelition(int arr[],int pos){
    if(pos>n){
        printf("Invalid Position\n");
        return ;
    }
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    printArray(arr);
}

void valueDeletion(int arr[],int v){
    for(int i=0;i<n;i++){
        if(arr[i]==v){
            positionDelition(arr,i+1);
            return;
        }
    }
}

int main(){
    int val,pos;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printArray(arr);
    printf("\nEnter element to be deleted :");
    scanf("%d",&val);
    valueDeletion(arr,val);
    printf("\nEnter position of the element to be deleted :");
    scanf("%d",&pos);
    positionDelition(arr,pos);
}