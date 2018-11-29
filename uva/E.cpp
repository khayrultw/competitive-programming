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



int costn[30001],cost[30002];
VECI vec[30001];
bool visited[30001];

void bfs(int x,int y)
{
    int tmp;
    queue<int> q;
    q.push(x);
    costn[x]=cost[x];
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        forip(0,vec[tmp].size()-1)
        {
            if(visited[vec[tmp][i]]==false)
            {
                visited[vec[tmp][i]] = true ;
                costn[vec[tmp][i]]=costn[tmp]+cost[vec[tmp][i]];
                if(vec[tmp][i]==y)
                    return ;
                q.push(vec[tmp][i]);
            }
        }
    }
}
int main()
{
    int n,q,a,b,c,t,sum,cas=0;
    cin >> t ;
    while(++cas<=t)
    {
        cin >> n;
        forip(0,n-1)
            scanf("%d",&cost[i]);
        forip(1,n-1)
        {
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        cout << "Case " << cas << ":" << endl;
        cin >> q ;
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                 cost[b] = c;
            }
            else
            {
                memset(visited,false,sizeof(visited));
                bfs(b,c);
                printf("%d\n",costn[c]);
            }
        }
        forip(0,30000)
            vec[i].clear();
    }
    return 0;
}

