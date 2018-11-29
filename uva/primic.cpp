
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

#define MAX 1000000
#define MOD 1000000007

int status[MAX/32+1] ;
int prim[80000];
map<long long,long long> mp ;
map<long long,long long>::iterator it;

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
    cout << k << endl;
}
long long divisor(int n)
{
    long long sum = 0,i;
    for(i=1;i<=mp[n];i++)
    {
        sum = sum + pow(n,i) ;
    }
    return sum ;
}

long long BigMod(int n,int p)
{
    if(p==0)
        return 1;
    if(p&1)
        return ((n%MOD)*BigMod(n,p-1))%MOD ;
    long long tmp;
    tmp = BigMod(n,p/2)%MOD ;
    return (tmp*tmp)%MOD;
}
int main()
{
    sieve(1000000);
    long long t,cas=0,n,m,sum;
    cin >> t ;
    while(++cas<=t)
    {
        cin >> n >> m ;
        for(int i=0;prim[i]<=sqrt(n);)
        {
            if(n%prim[i]==0)
            {
                mp[prim[i]]++;
                n=n/prim[i];
            }
            else i++;
        }
        if(n>1)
            mp[n]++;
        sum = 0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            sum+=divisor(it->first);
            cout << sum << endl;
        }
        sum = BigMod(sum,m);
        printf("Case %d: %lld\n",cas,sum);
        mp.clear();
    }
    return 0;
}
