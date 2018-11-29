
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,vei[20],t,cas=0;
    bool vis[20];
    scanf("%d",&t);
    while(++cas<=t)
    {
        scanf("%d%d",&n,&m);
        memset(vis,true,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%d",&vei[i]);
        sort(vei,vei+n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                for(int j=i;j<n;j++)
                {
                    if(vei[j]%vei[i]==0)
                        vis[j] = false;
                }
                sum += floor(1.00*m/vei[i]);
            }
        }
        printf("Case %d: %d\n",cas,sum);
    }
    return 0;
}
