#include<bits/stdc++.h>

using namespace std;

void bfs(int n) ;
vector<int>v[100001] ;
int sum[100001],summ=0,nod=0 ;
bool visited[100001] ;

int main()
{
    fill(visited,visited+100001,false) ;

    int n,a,b,i;
    cin >> n ;
    for(i=0;i<n-1;i++)
    {
        cin >> a >> b ;
        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }
    bfs(1) ;
    printf("%.10lf\n",1.00*summ/nod );
    return 0 ;
}

void  bfs(int n)
{
    int tmp, i ;
    bool f ;
    sum[n] = 0 ;
    queue<int> q ;
    q.push(n) ;
    visited[n] = true ;
    while(!q.empty())
    {
        tmp = q.front() ;
        q.pop() ;
        f = false ;
        for(i=0;i<v[tmp].size();i++)
        {
            if(visited[v[tmp][i]]==false)
            {
                sum[v[tmp][i]] = sum[tmp] + 1 ;
                q.push(v[tmp][i]) ;
                visited[v[tmp][i]] = true ;
                f = true ;
            }
        }
        if(!f)
        {
            summ+=sum[tmp] ;
            nod++;
        }
    }
}
