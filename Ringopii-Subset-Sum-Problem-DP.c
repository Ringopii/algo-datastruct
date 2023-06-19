// Implementation of Subset Sum Problem using Dynamic Programming

#include <stdio.h>
#include <stdbool.h>

bool subsetDP(int set[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    int r, c;

    for (r = 0; r <= n; r++)
        dp[r][0] = true;

    for (c = 1; c <= sum; c++)
        dp[0][c] = false;

    for (r = 1; r <= n; r++)
    {
        for (c = 1; c <= sum; c++)
        {
            if (dp[r - 1][c] == true)
                dp[r][c] = true;

            else
            {
                if (set[r - 1] > c)
                    dp[r][c] = false;
                else
                    dp[r][c] = dp[r - 1][c] || dp[r - 1][c - set[r - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the value of sum: ");
    scanf("%d", &sum);

    if (subsetDP(set, n, sum) == true)
        printf("\nSubset found\n");
    else
        printf("\nNo subset found\n");
        
    return 0;
}