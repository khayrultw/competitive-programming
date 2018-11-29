#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
#define INF 0x3ff3ff3f

int arr[MAX],tree[3*MAX],freq[3*MAX],calFreq[3*MAX];

int makeTree(int low,int high,int node)
{
    if(low==high)
    {
        tree[node] = arr[low] ;
        freq[node] = 1;
        return arr[low] ;
    }
    int mid = (low+high)/2;
    int a = 2*node ;
    int x,y;
    x = makeTree(low,mid,a);
    y = makeTree(mid+1,high,a+1);
    if(x==y)
    {
        freq[node] = freq[a]+freq[a+1] ;
        tree[node] = x ;
        return x ;
    }
    int w=freq[a],z=freq[a+1] ;
    for(int i=mid+1;i<=high;i++)
    {
        if(arr[i]==x)
            w++;
        else
            break;
    }
    for(int i=mid;i>=low;i--)
    {
        if(arr[i]==y)
            z++;
        else
            break;
    }
    if(w<z)
    {
        freq[node] = z ;
        tree[node] = y ;
        return y ;
    }
    else
    {
        freq[node] = w;
        tree[node] = x ;
        return x ;
    }
}

int query(int low,int high,int i,int j,int node)
{
    if(j<low || high<i)
        return 0;
    if(i<=low && high<=j)
    {
        calFreq[node] = freq[node] ;
        return tree[node] ;
    }
    int mid = (low+high)/2 ;
    int x,y;
    x = query(low,mid,i,j,2*node) ;
    y = query(mid+1,high,i,j,2*node+1) ;
    if(x==y)
    {
        calFreq[node] = calFreq[2*node]+calFreq[2*node+1] ;
        return x ;
    }
    if(calFreq[2*node]<calFreq[2*node+1])
    {
        calFreq[node] = calFreq[2*node+1] ;
        return y ;
    }
    else
    {
        calFreq[node] = calFreq[2*node] ;
        return x ;
    }

}

int main()
{
    int n,q,i,a,b;
    FILE *fp = fopen("File.txt","w");
    while( scanf("%d",&n) && n!=0 )
    {
        scanf("%d",&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]) ;
        }
        makeTree(1,n,1);
        for(i=1;i<=3*n;i++)
             cout <<i << " " << tree[i] << " " << freq[i] << endl;
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b) ;
            query(1,n,a,b,1);

            printf("%d\n",calFreq[1]) ;
        }
    }
    fclose(fp);
    return 0;
}

