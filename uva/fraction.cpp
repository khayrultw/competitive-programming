#include<bits/stdc++.h>

using namespace std;

double mod(double a,double b);
double gcd(double a,double b);

int main()
{
    int t ;
    double a,b,gc;
    cin >> t ;
    while( t-- )
    {
        scanf("%lf / %lf",&a,&b);
        gc = gcd(a,b);
        a = a/gc ;
        b = b/gc ;
        printf("%.0lf / %.0lf\n",a,b);
    }
    return 0;
}

double mod(double a,double b)
{
    int c = a/b ;
    return a-b*c ;
}

double gcd(double a,double b)
{
    if(mod(a,b)==0)
        return b ;
    return gcd(b,mod(a,b)) ;
}
