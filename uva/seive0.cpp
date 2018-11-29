#include<bits/stdc++.h>

using namespace std;

#define mx 1000000

bool Check(int N,int pos);
int Set(int N,int pos);
void sieve(int N);

int status[(mx/32)+2];
int prim[80000];

int main()
{
    sieve(1000000) ;
    int n,i,j;
    while(cin >> n && n!=0)
    {
        int tmp = n ;
        n = abs(n);
        if(tmp<0)
            cout << tmp << " = -1 x " ;
        else
            cout << tmp << " = " ;
        bool f = false ;
        for(i=0;prim[i]<=sqrt(n);)
        {
            if(n%prim[i]==0)
            {
                cout << prim[i] << " x " ;
                n=n/prim[i] ;
            }
            else i++;
        }
        if(n>1)
            cout << n << endl;
    }
    return 0;
}

void sieve(int N)
{
	 int i, j, root;
     root = sqrt( N );
     for( i = 3; i <= root; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }

	 int sum = 0 ;
	 prim[sum++] = 2 ;
	 for(i=3;i<=N;i+=2)
		 if( Check(status[i>>5],i&31)==0)
	 	     prim[sum++] =  i ;
}

bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos)
{
	return N=N | (1<<pos);
}
