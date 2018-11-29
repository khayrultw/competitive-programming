#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

#define MAX 10000000

int status[MAX/32+1] ;
int prim[665000];

int check(int n,int p)
{
    return n&(1<<p);
}
int Set(int n,int p)
{
    return n | (1<<p) ;
}

void sieve(int n)
{
    int root,i,j;
    root = sqrt(n) ;
    for(i=3;i<=root;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(j=i*i;j<=n;j+=i<<1)
            {
                status[j>>5] = Set(status[j>>5],j&31) ;
            }
        }
    }
    int k=0;
    prim[k++] = 2 ;
    for(i=3;i<=n;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
            prim[k++] = i ;
    }
}

int main()
{
    sieve(MAX);
    int t, cas = 0, n, way;
    cin >> t ;
    while(++cas<=t)
    {
        cin >> n ;
        way = 0 ;
        if(n==4)
        {
            printf("Case %d: 1\n", cas);
            continue;
        }
       for(int i = 0; prim[i]<=n/2; i++)
        {
            int tmp = n-prim[i] ;
            if(tmp&1 && check(status[tmp>>5],tmp&31)==0)
            {
                way++;
            }
        }
        printf("Case %d: %d\n", cas, way);
    }
    return 0;
}
