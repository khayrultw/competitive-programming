#include<bits/stdc++.h>

using namespace std;

#define mx 65000

int status[mx/32] ;
int chr[65000] = {};
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
}

int Bigmod(int a,int b,int m)
{
    if(b==0)
        return 1 ;
    if(b&1)
    {
        return ((a%m)*Bigmod(a,b-1,m))%m;
    }
    else
    {
        int x = Bigmod(a,b/2,m) ;
        return (x*x)%m;
    }
}

int main()
{
    int n,i;
    sieve(65000);
    bool f ;
    ofstream fcout("file.txt");
    for(int j=2;j<65000;j++)
    {
        if(check(status[j>>5],j&31)==0){
             if(j==62745)
                    cout << "k" << endl;
            continue;
        }
        f = true ;
        for(i=2;i<j;i++)
        {

            if(Bigmod(i,j,j)!=i)
            {
                if(j==62745)
                    cout << i << endl;
                f = false ;
                break;
            }
        }
        if(f&&(!((n&1) && check(status[n>>5],n&31)==0)))
        {
            chr[j]=1;
        }
    }
    cout << Bigmod(2,62745,62745) << endl;
    while(cin >> n && n!=0)
    {
         if(chr[n]==1)
            fcout << "The number " << n << " is a Carmichael number." << endl;
         else
            fcout << n << " is normal." << endl;
    }
    return 0;
}
