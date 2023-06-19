//Implementation of Matrix Chain Multiplication(MCM)
//Problem using Dynamic Programming

#include <stdio.h>
#define MAX 999999999

int MCM(int arr[], int n)
{
    int m[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = 0;
        }
    }

    for (int l = 1; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            if (i == j)
            {
                m[i][j] = 0;
            }
            else
            {
                m[i][j] = MAX;
                for (int k = i; k < j; k++)
                {
                    int min = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (min < m[i][j])
                        m[i][j] = min;
                }
            }
        }
    }

    printf("m-table: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\t%d ", m[i][j]);
        }
        printf("\n");
    }

    return m[1][n - 1];
}

int main()
{
    int n, i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter chain of matrices: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nMinimum number of Scalar operations needed is %d\n ", MCM(arr, n));
    
    return 0;
}