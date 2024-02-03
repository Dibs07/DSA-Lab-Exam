#include<stdio.h>

void main(){
    int n;
    printf("Enter the number of elements you want in array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0],sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum>max){
                max=sum;
            }
        }
    }
    printf("Max sum subarray is %d",max);
}