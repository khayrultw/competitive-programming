#include<bits/stdc++.h>

using namespace std;

#define mx 100000000

int status[mx/32] ;
int prim[348515];
long long tot[5000001];

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
	//freopen("output", "w", stdout);
	sieve(5000050);
	for(int j = 2; j <= 5000000; j++) tot[j] = j;
	for(int i = 0; prim[i] < 5000000; i++)
	{
		for(int j = prim[i]; j <= 5000000; j+=prim[i])
		{
			tot[j] = tot[j]*(prim[i]-1)/prim[i];
		}
		//cout << prim[i] << endl;
	}
	tot[1] = 0;
	for(int j = 3; j <= 5000000; j++) 
	{
		tot[j] = tot[j-1]+tot[j]*tot[j];
	}
	int t,cas = 0;
	cin >> t;
	while(++cas<=t)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		unsigned long long sum = 0;
		sum = tot[b] - tot[a-1];
		printf("Case %d: %llu\n", cas, sum);
	}
	return 0;
}
