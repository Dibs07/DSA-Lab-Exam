#include <stdio.h>

int r1, r2, c1, c2;

void matrixMulti(int a[r1][c1], int b[r2][c2], int c[r1][c2])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(*(c + i) + j) = 0;
            for (int k = 0; k < r2; ++k)
            {
                *(*(c + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
            }
        }
    }
}

void printMatrix(int r, int c,int arr[][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter no. of rows of the first matrix");
    scanf("%d", &r1);
    printf("Enter no. of colums of the first matrix");
    scanf("%d", &c1);
    printf("Enter no. of rows of the second matrix");
    scanf("%d", &r2);
    printf("Enter no. of columns of the second matrix");
    scanf("%d", &c2);

    int m1[r1][c1], m2[r2][c2], m3[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", (*(m1+i)+j));
        }
    }
    printMatrix( r1, c1,m1);
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", (*(m2+i)+j));
        }
    }
    printMatrix( r2, c2,m2);
    if (c1 != r2)
    {
        printf("The matrices cannot be multiplied as they are not compatible.\n");
        return 0;
    }
    else
    {
        matrixMulti(m1, m2, m3);
        printMatrix(r1, c2,m3);
    }
}