#include <stdio.h>
int n, i, j;

void QuickSOrt(int a[], int l, int h)
{
    int mid;
    if (l >= h)
        return;
    mid = partition2(a, l, h);
    QuickSOrt(a, l, mid - 1);
    QuickSOrt(a, mid + 1, h);
    return;
}
int partition(int x[], int l, int h)
{
    int d = l, u = h, pivot = x[l], temp;
    while (d < u)
    {
        while (x[d] <= pivot )
            d++;
        while (x[u] > pivot)
            u--;
        if (d < u)
        {
            temp = x[d];
            x[d] = x[u];
            x[u] = temp;
        }
    }
    x[l] = x[u];
    x[u] = pivot;
    return u;
}
int partition2(int a[], int l, int h){
    int pivot=a[h];
    int j=l;
    int i=l-1;
    int temp;
    for(;j<h;j++){
        if(a[j]<pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
        i++;
        a[h]=a[i];
        a[i]=pivot;
        return i;
}

void main()
{
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int low = 0, high = n;
    int arr[n];
    printf("Enter Array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    QuickSOrt(arr, low, high);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}