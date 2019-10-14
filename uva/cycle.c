#include <stdio.h>

int adj[100][100];
int node, edge;
int vis[100], flag, print;

void dfs(int u, int prev)
{
    if(flag)
        return ;

    int i, j;
    vis[u] = 1;
    for(i = 0; i <= node; i++)
    {
        if(i == u || i == prev)
            continue;
        

        if(adj[u][i] && vis[i] == 1)
        {
            print = 1;
            flag = 1;
            vis[i] = 2;
        }

        if(adj[u][i] && !vis[i])
            dfs(i, u); 

    }
    if(print)
        printf("%d ", u);
    
    if(vis[u] == 2)
        print = 0;

    vis[u] = 3;

}

int main()
{
    int t, a, b, i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &node, &edge);

        for(i = 0; i <= node; i++)
        {
            vis[i] = 0;
            for(j = 0; j <= node; j++)
                adj[i][j] = 0;
        }

        for(i = 0; i < edge; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a][b] = 1;
            //adj[b][a] = 1;
        }

        for(i = 0; i <= node; i++)
        {
            if(!vis[i])
            {
                print = flag = 0;

                dfs(i, -1);

                if(flag)
                {
                    printf("Cycle detected\n");
                    goto L1;
                }
            }
        }
        printf("no Cycle\n");
        L1: ;
    }
    return 0;
}