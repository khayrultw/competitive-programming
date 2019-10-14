#include <stdio.h>

char grid[10][10];
int n, m;

int is_valid(int i, int j)
{
    if(i < 0 || j < 0)
        return 0;
    
    if(i >= n || j >= m)
        return 0;

    if(grid[i][j] == '2')
        return 0;
    
    return 1;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int dfs(int i, int j, int bomb)
{
    //printf("%d %d\n", i, j);
    int coin = 0;

    if(!is_valid(i, j))
        return 0;
    
    coin = max(coin, dfs(i-1, j-1, bomb));
    coin = max(coin, dfs(i-1, j+1, bomb));
    coin = max(coin, dfs(i-1, j, bomb));

    if(grid[i][j] == '1')
        coin++;
    return coin;
}

int main()
{
    int t, i, j, sx, sy;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        getchar();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                scanf("%c", &grid[i][j]);
                printf("%c ", grid[i][j]);
                getchar();

                if(grid[i][j] == 'S'){
                    //printf("%c\n", grid[i][j]);
                    sx = i;
                    sy = j;
                }
            }
            printf("\n");
        }
        printf("%d\n", dfs(sx, sy, 1));
    }
    return 0;
}

