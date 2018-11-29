#include<bits/stdc++.h>

using namespace std ;

double digit(long long n,long long a );

int main()
{
    long long n,r;
    double dn,dnr,dr;
    while( cin >> n >> r )
    {
        if(r > (n-r))
        {
            dn = digit(n,r) ;
            dnr = digit(n-r,1) ;
            cout << (long long)(dn-dnr+1) << endl;
        }
        else
        {

            dn = digit(n,n-r) ;
            dr = digit(r,1) ;
            cout << (long long)(dn-dr+1) << endl;
        }

    }
    return 0;
}

double digit(long long n,long long a)
{
    long long i ;
    double tmp,sum=0;
    for(i=a+1;i<=n;i++)
    {
        sum +=log10(i) ;
    }
    return sum ;
}
