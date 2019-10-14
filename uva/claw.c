#include <stdio.h>

int adj[301][301];
int vis[301];
int n, flag;

void dfs(int u)
{
    int i, j;

    if(flag)
        return ;

    for(i = 0; i < n; i++)
    {
        if(i == u)
            continue;
        
        if(adj[u][i])
        {
            if(vis[i] == vis[u]){
                flag = 1;
                return ;
            }

            if(!vis[i])
            {
                vis[i] = vis[u]^3;
                dfs(i);
            }
        }
    }
}

int main()
{
    
    int t, i, j;
    int e, a, b;
    int ans, one, two;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &e);
        if(e == 0)
        {
            ans = n;
            goto L2;
        }
        for(i = 0; i <= n; i++)
        {
            vis[i] = 0;
            for(j = 0; j <= n; j++)
                adj[i][j] = 0;
        }

        for(i = 0; i < e; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        ans = 0;
        for(i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                flag = 0;
                dfs(i);
                if(flag)
                    goto L1;
                one = 0;
                two = 0;
                for(j = 0; j < n; j++)
                {
                
                    if(vis[j] == 1)
                        one++;
                    
                    if(vis[j] == 2)
                        two++;
                    
                    if(vis[j])
                        vis[j] = 3;
                }
                ans += (one<two)?one:two;
                if(one == 0)
                    ans += two;
                if(two == 0)
                    ans += one;
            }
        }
        L2: printf("%d\n", ans);
        continue;
        L1: printf("-1\n");
    }
    return 0;
}