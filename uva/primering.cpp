#include<bits/stdc++.h>

using namespace std;

int prim[17],n,cas=0;
bool visited[17];

bool isPrime(int n)
{
    if(n==2)
        return true;
    if(n==1)
        return false;
    if(n%2==0)
        return false;
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void print(int k)
{
    if(k==n)
    {
        if(isPrime(prim[1]+prim[n]))
        {
            for(int i=1;i<n;i++)
                printf("%d ",prim[i]);
            printf("%d\n",prim[n]);
        }
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(visited[i]==false)
        {
            if(isPrime(prim[k]+i))
            {
                prim[k+1] = i ;
                visited[i] = true;
                print(k+1);
                visited[i]=false;

            }
        }
    }
}

int main()
{
    while( cin >> n )
    {
        memset(visited,false,sizeof(visited));
        prim[1] = 1 ;
        if(cas!=0)
            printf("\n");
        printf("Case %d:\n",++cas);
        print(1);
    }
    return 0;
}
