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
#define forip(a,n) for(int i = a; i<=n; i++)
#define forin(a,n) for(int i = n; i>=a; i--)
#define forjp(a,n) for(int j = a; j<=n; j++)
#define _ << " " <<
#define PB push_back

char maze[11][11];
bool f, visited[11][11];
int cost[11][11],n;
struct node{
    int a,b;
};
int bfs(int i,int j)
{
    node ob,tmp;
    f = false;
    queue<node>q;
    ob.a = i;
    ob.b = j;
    q.push(ob);
    cost[i][j]=0;
    while(!q.empty())
    {
        ob=q.front();
        q.pop();

        if(ob.a>0 && maze[ob.a-1][ob.b]=='.')
        {
            if(visited[ob.a-1][ob.b]==false)
            {
                if(maze[ob.a-1][ob.b]=='X'){
                    return cost[ob.a][ob.b]+1;
                    cout << maze[ob.a-1][ob.b] << endl;
                }
                visited[ob.a-1][ob.b] = true;
                cost[ob.a-1][ob.b] = cost[ob.a][ob.b]+1;
                tmp.a = ob.a-1;
                tmp.b = ob.b;
                q.push(tmp);
            }
        }
        if(ob.a+1<n && maze[ob.a+1][ob.b]=='.')
        {
            if(visited[ob.a+1][ob.b]==false)
            {

                if(maze[ob.a-1][ob.b]=='X'){
                    return cost[ob.a][ob.b]+1;
                    cout << maze[ob.a-1][ob.b] _ "OK" << endl;
                }
                visited[ob.a+1][ob.b] = true;
                cost[ob.a+1][ob.b] = cost[ob.a][ob.b]+1;
                tmp.a = ob.a+1;
                tmp.b = ob.b;
                q.push(tmp);
            }
        }
        if(ob.b>0 && maze[ob.a][ob.b-1]=='.')
        {
            if(visited[ob.a][ob.b-1]==false)
            {
                if(maze[ob.a-1][ob.b]=='X'){
                    return cost[ob.a][ob.b]+1;
                    cout << maze[ob.a][ob.b-1] << endl;
                }
                visited[ob.a][ob.b-1] = true;
                cost[ob.a][ob.b-1] = cost[ob.a][ob.b]+1;
                tmp.a = ob.a;
                tmp.b = ob.b-1;
                q.push(tmp);
            }
        }
        if(ob.b+1<n && maze[ob.a][ob.b+1]=='.')
        {
            if(visited[ob.a][ob.b+1]==false)
            {

                if(maze[ob.a-1][ob.b]=='X'){
                    return cost[ob.a][ob.b]+1;
                    cout << maze[ob.a][ob.b+1] << endl;
                }
                visited[ob.a][ob.b+1] = true;
                cost[ob.a][ob.b+1] = cost[ob.a][ob.b]+1;
                tmp.a = ob.a;
                tmp.b = ob.b+1;
                q.push(tmp);
            }
        }
    }
    return 0;
}

int check(int a1,int b1,int a2,int b2,int a3,int b3)
{
        int mx = 0,sum,maxx;
        bool flag = true ;
        memset(visited,false,sizeof(visited));
        sum = bfs(a1,b1);
        if(sum==0)
        {
            return 0;
        }
        if(sum>mx)
            mx = sum ;
        memset(visited,false,sizeof(visited));
        visited[a1][b1] = true;
        sum = bfs(a2,b2);
        if(sum==0)
        {
           return 0;
        }
        if(sum>mx)
            mx = sum ;
        memset(visited,false,sizeof(visited));
        sum = bfs(a3,b3);
        if(sum>mx)
            mx = sum ;
        if(sum==0)
        {
           return 0;
        }
        return mx ;
}
int main()
{
    int t,cas=0,a1,a2,a3,b1,b2,b3;
    cin>> t;
    while(++cas<=t)
    {
        cin >> n ;
        forip(0,n-1)
            scanf("%s",maze[i]);
        forip(0,n-1)
        forjp(0,n-1)
        {
            if(maze[i][j]=='A')
            {
                a1=i;
                b1=j;
            }
            if(maze[i][j]=='B')
            {
                a2=i;
                b2=j;
            }
            if(maze[i][j]=='C')
            {
                a3=i;
                b3=j;
            }
        }
        int sum,maxx=100;
        sum = check(a1,b1,a2,b2,a3,b3);
        if(sum==0) goto l;
        maxx = sum ;
    l: sum = check(a1,b1,a3,b3,a2,b2);
        if(sum==0) goto l1;
        if(sum<maxx)
        maxx=sum;
    l1: sum=check(a2,b2,a1,b1,a3,b3);
        if(sum==0) goto l2;
        if(sum<maxx)
            maxx=sum;
    l2: sum = check(a2,b2,a3,b3,a1,b1);
        if(sum==0) goto l3;
        maxx = sum ;
    l3: sum = check(a3,b3,a1,b1,a2,b2);
        if(sum==0) goto l4;
        if(sum<maxx)
        maxx=sum;
    l4: sum=check(a3,b3,a2,b2,a1,b1);
        if(sum==0) goto l5;
        if(sum<maxx)
            maxx=sum;
    l5: if(maxx==0)
        printf("Case %d: trapped\n",cas);
        else
        printf("Case %d: %d\n",cas,maxx);
    }
    return 0;
}

