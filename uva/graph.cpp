#include<bits/stdc++.h>

using namespace std;

vector<int> v[100001];
int flag[100001];
bool visited[100001];
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    flag[n] = 1;
    int tmp ;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        for(int i = 0; i<v[tmp].size();i++)
        {
            if(visited[v[tmp][i]]==false)
            {
                visited[v[tmp][i]] = true;
                flag[v[tmp][i]] = -1*flag[tmp];
                q.push(v[tmp][i]);
            }
        }
     }
 }
int main()
{
    int a,b,n;
    cin >> n ;
    memset(visited,false,sizeof(visited));
    for(int i = 1;i<n;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    int x,y;
    x = y = 0;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==1)
            x++;
        else
            y++;
    }
    int ans = x*y-n+1;
    cout << ans << endl;
    return 0;
}

