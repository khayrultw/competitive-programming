#include<bits/stdc++.h>

using namespace std;

#define MOD 1000003
long long dp
long long com(long long n,long long r)
{
    if(n==0)
        return 0;
    if(r==0)
        return 1;
    long long a,b;
    a = com(n-1,r);
    b = com(n-1,r-1);
    return (a+b)%MOD;
}
