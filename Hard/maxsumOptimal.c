#include <stdio.h>
#include <limits.h>
// Kadane's Algorithm
void main()
{
    // int n;
    // printf("Enter the number of elements you want in array: ");
    // scanf("%d",&n);
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     scanf("%d",&arr[i]);
    // }
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = INT_MIN, sum = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
            a = c;
            b = i;
        }
        if (sum < 0)
        {
            sum = 0;
            c = i + 1;
        }
    }
    printf("Max sum subarray is %d", max);
    printf("Starting from index %d ", a);
    printf("Ending at index %d", b);
}