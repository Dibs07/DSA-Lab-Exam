#include <stdio.h>

int n;

void Merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1,n2 = h - m;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = a[i++];
    }

    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}

void MergeSort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
    return;
}

void printArray(int arr[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printArray(arr);
    printf("\n");
    MergeSort(arr, 0, n);
    printArray(arr);
}