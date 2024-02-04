#include<stdio.h>
#include<limits.h>
//Kadane's Algorithm
void main(){
    int n;
    printf("Enter the number of elements you want in array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>max){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    printf("Max sum subarray is %d",max);
}