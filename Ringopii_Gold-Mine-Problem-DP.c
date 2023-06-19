// Implementation of Gold Mine Problem using Dynamic Programming

#include <stdio.h>
#include <stdlib.h>

int maxGoldAmount(int r, int c, int GM[r][c])
{
    int DP_T[r][c];

    for (int row = 0; row < r; row++)
    {
        DP_T[row][0] = GM[row][0];
    }

    for (int col = 1; col < c; col++)
    {
        for (int row = 0; row < r; row++)
        {
            DP_T[row][col] = GM[row][col];
            int leftAmount = DP_T[row][col - 1];

            if (row - 1 >= 0)
            {
                if (DP_T[row - 1][col - 1] > leftAmount)
                {
                    leftAmount = DP_T[row - 1][col - 1];
                }
            }

            if (row + 1 < r)
            {
                if (DP_T[row + 1][col - 1] > leftAmount)
                {
                    leftAmount = DP_T[row + 1][col - 1];
                }
            }

            DP_T[row][col] = DP_T[row][col] + leftAmount;
        }
    }

    int maxGold = DP_T[0][c - 1];

    for (int row = 1; row < r; row++)
    {
        if (DP_T[row][c - 1] > maxGold)
        {
            maxGold = DP_T[row][c - 1];
        }
    }

    return maxGold;
}

void cell(int r, int c, int GM[r][c])
{
    int DP_T[r][c];

    for (int row = 0; row < r; row++)
    {
        DP_T[row][0] = GM[row][0];
    }

    for (int col = 1; col < c; col++)
    {
        for (int row = 0; row < r; row++)
        {
            DP_T[row][col] = GM[row][col];
            int leftAmount = DP_T[row][col - 1];

            if (row - 1 >= 0)
            {
                if (DP_T[row - 1][col - 1] > leftAmount)
                {
                    leftAmount = DP_T[row - 1][col - 1];
                }
            }
            if (row + 1 < r)
            {
                if (DP_T[row + 1][col - 1] > leftAmount)
                {
                    leftAmount = DP_T[row + 1][col - 1];
                }
            }

            DP_T[row][col] = DP_T[row][col] + leftAmount;
        }
    }

    int index = DP_T[0][c - 1];
    int indexRow = 0;
    int indexRow1 = 0;

    for (int row = 1; row < r; row++)
    {
        if (DP_T[row][c - 1] > index)
        {
            index = DP_T[row][c - 1];
            indexRow = row;
        }
    }

    printf("\n\nAnd it is in (%d,%d) cell\n\n", indexRow, c - 1);

    for (int row = 1; row < r; row++)
    {
        if ((row != indexRow && DP_T[row][c - 1] == DP_T[indexRow][c - 1]))
        {
            indexRow1 = row;
            printf("and (%d,%d) cell\n\n", indexRow1, c - 1);
        }
    }
}

int main()
{
    int r, c;

    printf("Enter matrix dimension for row: ");
    scanf("%d", &r);

    printf("Enter matrix dimension for column: ");
    scanf("%d", &c);

    int GM[r][c];
    printf("Enter gold amount in each cell:\n");

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            scanf("%d", &GM[row][col]);
        }
    }

    printf("\nMaximum amount of gold can be collected from this mine is %d units", maxGoldAmount(r, c, GM));
    cell(r, c, GM);
    
    return 0;
}