#include <stdio.h>
#include <limits.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        printf("\n");
}

int main()
{
    int n, k = 0;
    printf("Enter size:");
    scanf("%d", &n);
    int arr[n], max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printArray(arr, n);
    printf("\nLargest element is %d\n", max);
    int count[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    printArray(count, max + 1);
    for (int i = 0; i < max + 1; i++)
    {
        while (count[i]--)
        {
            arr[k++] = i;
        }
    }
    printArray(arr,n);
}