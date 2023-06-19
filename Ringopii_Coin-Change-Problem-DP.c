// Implementation of Coin Change Problem using Dynamic Programming

#include <stdio.h>

int wayCount(int coinSet[], int coinSizeR, int coinAmountC)
{
    int dp[coinSizeR + 1][coinAmountC + 1];

    for (int r = 0; r <= coinSizeR; r++)
    {
        for (int c = 0; c <= coinAmountC; c++)
        {
            if (r == 0)
                dp[0][c] = 0;
            else if (c == 0)
                dp[r][0] = 1;
            else if (coinSet[r - 1] > c)
                dp[r][c] = dp[r - 1][c];
            else
                dp[r][c] = dp[r - 1][c] + dp[r][c - coinSet[r - 1]];
        }
    }

    return dp[coinSizeR][coinAmountC];
}

int main(void)
{
    int coinSet[100];
    int coinSizeR;
    int coinAmountC;

    printf("Enter the number of coins from coin set: \n");
    scanf("%d", &coinSizeR);

    printf("Enter the whole set of coins: \n");

    for (int i = 0; i < coinSizeR; i++)
    {
        scanf("%d", &coinSet[i]);
    }

    printf("Enter the amount of coins to get change: \n", coinAmountC);
    scanf("%d", &coinAmountC);

    printf("Total number of ways to get change: %d \n", wayCount(coinSet, coinSizeR, coinAmountC));
    
    return 0;
}