#include<bits/stdc++.h>

using namespace std ;

double BigMod(double n,double p);
double Mod(double a,double b) ;

int main()
{
    double a,b;
    while(cin >>a >> b && (a!=0 || b!=0))
    {
        cout << BigMod(a,b) << endl;
    }
    return 0;
}

double BigMod(double n,double p)
{
    if(p==0)
        return 1 ;
    if(Mod(p,2)==1)
    {
        return Mod((Mod(n,10) * BigMod(n,p-1)),10) ;
    }
    else
    {
        double x = BigMod(n,p/2) ;
        return Mod(x*x,10);
    }
}

double Mod(double a,double b)
{
    int x = a/b;
    return a-x*b;
}
