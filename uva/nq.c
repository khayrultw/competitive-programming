#include <stdio.h>

int game[10][10];
int n;

int is_safe(int r, int c)
{
    int i, j;
    for(i = r-1; i >= 0; i--)
    {
        if(game[i][c])
            return 0;
    }

    for(i = r, j = c;i>=0 && j>=0; i--,j--)
    {
        if(game[i][j])
            return 0;
    }

    for(i = r, j = c; i >= 0 && j < n; i--, j++)
        if(game[i][j])
            return 0;
    
    return 1;
}

int check(int row)
{
    if(row == n)
        return 1;

    int i, sum = 0;
    for(i = 0; i < n; i++)
    {
        if(is_safe(row, i))
        {
            game[row][i] = 1;
            sum += check(row+1);
            game[row][i] = 0;
        }
    }
    return sum;
}

int main()
{
    n = 8;
    printf("%d\n", check(0));
}