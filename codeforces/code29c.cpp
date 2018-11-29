#include<bits/stdc++.h>

using namespace std;

#define MAX 200001

vector<int> v[MAX];
int ver[MAX],gcd[MAX];
bool visited[MAX];

void dfs(int n,int gc)
{
    visited[n]=true;
    gcd[n]=max(ver[n],gc);
    for(int i=0;i<v[n].size();i++)
    {
        if(visited[v[n][i]]==false)
        {
            dfs(v[n][i],gcd[n]);
        }
    }
}

int main()
{
    int n,i,a,b;
    memset(visited,false,sizeof(visited));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ver[i]) ;
    }
    for(i=1;i<n;i++)
    {
        cin >> a >> b ;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    for(i=1;i<n;i++)
        printf("%d ",gcd[i]) ;
    printf("%d\n",gcd[n]) ;
    return 0;
}
