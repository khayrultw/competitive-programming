#include<bits/stdc++.h>

using namespace std;

int divisor(int a[],int n)
{
    int i,j,k=1,sq;
    a[1] = 1 ;
    if(n==1)
        return k;
    if(n==2 || n==3)
    {
        a[++k] = n;
        return k;
    }
    sq = sqrt(n) ;
    for(i=2;i<sq;i++)
    {
        if(n%i==0)
        {
            a[++k] = i ;
            a[++k] = n/i;
        }
    }
    if(sq*sq==n)
    {
        a[++k] = sq ;
        a[++k] = n;
        return k;
    }
    if(n%sq==0)
    {
        a[++k] = sq ;
        a[++k] = n/sq ;
    }
    a[++k] = n ;
    return k;
}

double proba(int n)
{
    if(n==1)
        return 0;
    int d[1000],k;
    double x,sum=0;
    k = divisor(d,n) ;
    for(int i=2;i<=k;i++)
        sum += proba(n/d[i]) ;

    x = (double)(k+sum)/(k-1);
    //cout << x << " " << n << endl;
    return x ;
}
int main()
{
    int t,cas=0,n;
    cin >> t ;
    while(++cas<=t)
    {
        cin >> n ;
        printf("Case %d: %.9lf\n",cas,proba(n));
    }
    return 0;
}
