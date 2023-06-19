// Implementation of Minimum Cost Path/Minimum Path Sum Problem using Dynamic Programming

#include <stdio.h>

int minCostPath(int r, int c, int grid_cost[r][c])
{
    int DP_T[r][c];
    DP_T[0][0] = grid_cost[0][0];

    for (int col = 0; col < c; col++)
    {
        DP_T[0][col] = grid_cost[0][col] + DP_T[0][col - 1];
    }

    for (int row = 1; row < r; row++)
    {
        DP_T[row][0] = grid_cost[row][0] + DP_T[row - 1][0];
    }

    for (int row = 1; row < r; row++)
    {
        for (int col = 1; col < c; col++)
        {
            DP_T[row][col] = grid_cost[row][col] + min(DP_T[row - 1][col], DP_T[row][col - 1]);
        }
    }

    return DP_T[r - 1][c - 1];
}

int min(int a, int b)
{
    int m = (a < b) ? a : b;
    return m;
}

int main()
{
    int r, c;

    printf("Enter matrix dimension for row: ");
    scanf("%d", &r);

    printf("Enter matrix dimension for column: ");
    scanf("%d", &c);

    int grid_cost[r][c];

    printf("Enter grid cost in each cell:\n");

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            scanf("%d", &grid_cost[row][col]);
        }
    }

    printf("\nMinimum cost is %d units\n\n", minCostPath(r, c, grid_cost));
    
    return 0;
}