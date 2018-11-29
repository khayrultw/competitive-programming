#include<bits/stdc++.h>

using namespace std;

#define mx 100000000

int status[mx/32] ;
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
    //clock_t t = clock();
    sieve(10000000);
    //cout << (1.00*clock()-t)/CLOCKS_PER_SEC << endl;
   long long n,i,sum;
   while( cin >> n && n!=1 )
   {
        sum=0;
        for(i=0;prim[i]<=sqrt(n);)
        {
            if(n%prim[i]==0)
            {
                n/=prim[i];
                sum++;
            }
            else i++;
        }
        if(n>1)
            sum++;
        cout << sum << endl;
   }
    return 0;
}
