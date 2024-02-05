#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    if (m == n)
    {
        int arr[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Matrix is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        //Upper Triangular
        printf("The upper triangular matrix is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    printf("0 ");
                }
                else
                {
                    printf("%d ", arr[i][j]);
                }
            }
            printf("\n");
        }
        //Lower Triangular
        printf("The lower triangular matrix is:\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                {
                    printf("0 ");
                }
                else
                {
                    printf("%d ", arr[i][j]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("The matrix must be square.\n");
    }
}