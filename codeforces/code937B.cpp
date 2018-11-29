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
	sieve(31622);
	cout << prim[3400] << endl;
	int p, y;
	cin >> p >> y;
	if(y%2==0)
		y--;
	bool f = false;
	int tmp = p;
	if(p>31607)
		tmp = 31607;
	while(y>p)
	{
		for(int i = 1; prim[i]<=tmp; i++)
		{
			if(y%prim[i]==0)
			{
				f = true;
				break;
			}
		}
		if(!f)
		{
			cout << y << endl;
			return 0;
		}
		f = false;
		y-=2;
	}
	cout << -1 << endl;
	return 0;
}
