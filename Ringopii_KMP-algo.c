//Implementation of Knuth - Morris - Pratt(KMP) Algorithm along with LPS Table Creation

#include <stdio.h>
#include <string.h>

void lpsTable(int p_len, char pattern[p_len], int lps[p_len]);

void KMP(int t_len, char text[t_len], int p_len, char pattern[p_len])
{
    int lps[p_len];
    lpsTable(p_len, pattern, lps);
    int t = 0;
    int p = 0;

    while (t < t_len)
    {
        if (pattern[p] == text[t])
        {
            t++;
            p++;
        }
        if (p == p_len)
        {
            printf("Found pattern at index %d\n", t - p);
            p = lps[p - 1];
        }
        else if (t < t_len && pattern[p] != text[t])
        {
            if (p != 0)
            {
                p = lps[p - 1];
            }
            else
            {
                t++;
            }
        }
    }
}

void lpsTable(int p_len, char pattern[p_len], int lps[p_len])
{
    int len = 0;
    lps[0] = 0;
    int p = 1;

    while (p < p_len)
    {
        if (pattern[p] == pattern[len])
        {
            len++;
            lps[p] = len;
            p++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[p] = 0;
                p++;
            }
        }
    }
}

int main()
{
    char text[100];
    char pattern[100];
    int t_len, p_len;
    
    printf("Enter the text: ");
    scanf("%s", &text);

    printf("Enter the pattern: ");
    scanf("%s", &pattern);

    t_len = strlen(text);
    p_len = strlen(pattern);

    text[t_len];
    pattern[p_len];

    printf("Length of the text: %d\n", t_len);
    printf("Length of the pattern: %d\n", p_len);
    KMP(t_len, text, p_len, pattern);

    return 0;
}