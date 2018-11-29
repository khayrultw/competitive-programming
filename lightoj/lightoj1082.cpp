#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 0x3ff3ff3f

int arr[MAX],tree[3*MAX];
int makeTree(int low,int high,int node)
{
    if(low==high)
    {
        tree[node] = arr[low] ;
        return arr[low] ;
    }
    int mid = (low+high)/2;
    int minn = min(makeTree(low,mid,2*node),makeTree(mid+1,high,2*node+1)) ;
    tree[node] = minn ;
    return minn;
}

int query(int low,int high,int i,int j,int node)
{
    if(j<low || high<i)
        return INF;
    if(i<=low && high<=j)
        return tree[node] ;
    int mid = (low+high)/2 ;
    return min(query(low,mid,i,j,2*node),query(mid+1,high,i,j,2*node+1)) ;
}
int main()
{
    int n,q,i,t,cas=0,a,b;
    cin >> t ;
    while( ++cas<=t )
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]) ;
        }
        makeTree(1,n,1);
        printf("Case %d:\n",cas);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b) ;
            printf("%d\n",query(1,n,a,b,1)) ;
        }
    }
    return 0;
}
