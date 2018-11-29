#include<bits/stdc++.h>

using namespace std;

typedef long long llng;
typedef map<int,int> MPI;
typedef map<int,int> :: iterator MIT;
typedef vector<int> VECI;
typedef priority_queue<int> PQI;

#define PI acos(-1.0)
#define F first
#define S second
#define forip(a,n) for(int i = (int)a; i<=(int)n; i++)
#define forin(a,n) for(int i = (int)n; i>=(int)a; i--)
#define forjp(a,n) for(int j = (int)a; j<=(int)n; j++)
#define _ << " " <<

VECI vec[1001];
bool visited[1001];
int node[1001];

void dfs(int n)
{
    node[n]++;
    visited[n]=true;
    forip(0,vec[n].size()-1)
    {
        if(visited[vec[n][i]]==false)
            dfs(vec[n][i]);
    }
}

int main()
{
    int t,k,n,m,cas=0,p[101],a,b;
    cin >> t ;
    while(++cas<=t)
    {
        memset(node,0,sizeof(node));
        scanf("%d%d%d",&k,&n,&m);
        forip(1,k)
            scanf("%d",&p[i]);
        forip(1,m)
        {
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
        }
        int sum=0;
        forip(1,k)
        {
            memset(visited,false,sizeof(visited)) ;
            dfs(p[i]);
        }
        forip(1,n)
        {
            if(node[i]==k)
                sum++;
        }
        cout << "Case" _ cas << ": " << sum << endl;
        forip(0,1000)
            vec[i].clear();
    }
    return 0;
}
