#include <stdio.h>

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void main()
{
    int temp, f = 1, n, i, j;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n && f == 1; i++)
    {
        f = 0;
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                f = 1;
            }
        }
    }
    print(arr, n);
}
