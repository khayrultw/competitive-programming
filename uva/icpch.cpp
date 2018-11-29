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



int costn[201],cost[202],minp[201];
VECI vec[201];
bool visited[201];

void bfs(int x)
{
    int tmp,costmp;
    queue<int> q;
    q.push(x);
    costn[x]=0;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        forip(0,vec[tmp].size()-1)
        {
            if(visited[vec[tmp][i]]==false)
            {
                costmp = cost[vec[tmp][i]]-cost[tmp] ;
                cout << costmp _ tmp _ vec[tmp][i] << endl;
                visited[vec[tmp][i]] = true ;
                costn[vec[tmp][i]]=costn[tmp]+costmp*costmp*costmp;
                q.push(vec[tmp][i]);
            }
        }
    }
}

int main()
{
    int t,cas=0,n,m,a,b,q;
    cin >> t;
    while(++cas<=t)
    {
        cin >> n;
        forip(1,n)
            cin >> cost[i] ;
        cin >> m;
        forip(1,m)
        {
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
        }
        memset(visited,false,sizeof(visited));
        bfs(1);
        cin >> q;
        printf("Case %d:\n",cas);
        forip(1,q)
        {
            scanf("%d",&a);
            if(cost[a]>2 && visited[a]==true)
            printf("%d\n",costn[a]);
            else
            printf("?\n");
        }
        forip(0,200)
            vec[i].clear();
    }
    return 0;
}
