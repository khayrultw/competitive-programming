#include<bits/stdc++.h>

using namespace std;

vector<int> v[200] ;
int visited[200] ;

bool bfs(int n);

int main()
{
    int n,e,i,a,b;
    while( cin >> n && n!=0 )
    {
        fill(visited,visited+200,0);
        cin >> e ;
        for(i=0;i<e;i++)
        {
            cin >> a >> b ;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(bfs(a))
             cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
        for(i=0;i<200;i++)
            v[i].clear();
    }
    return 0;
}

bool bfs(int n)
{
    int tmp,i ;
    queue<int> q ;
    q.push(n) ;
    visited[n] = 1 ;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(i=0;i<v[tmp].size();i++)
        {
            if(visited[v[tmp][i]]==0)
            {
                visited[v[tmp][i]] = (visited[tmp]%2)+1 ;
                q.push(v[tmp][i]);
            }
            else
            {
                if(visited[v[tmp][i]]==visited[tmp])
                    return false ;
            }
        }
    }
    return true ;
}

