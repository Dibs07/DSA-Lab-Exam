#include <stdio.h>

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n, int f)
{
    if (f == 0)
    {
        return;
    }

    f = 0;
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            f = 1;
        }
    }
    bubbleSort(arr, n - 1, f);
}

void main()
{
    int n, i, j;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n, 1);
    print(arr, n);
}
