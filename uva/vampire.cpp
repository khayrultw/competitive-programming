#include<bits/stdc++.h>

using namespace std;

double wins(double n,double t,double a)
{
    double at = 6-t;
    if(n<=0)
        return t/6;
    double x = (wins(n-a,t,a)-(wins(n-2*a,t,a)*t/6))*6/at;
    return x;
}

int main()
{
    double x,y,a,b;
    while(cin >> x >> y >> a >> b)
    {
        double z = wins(y,a,b);
        cout << z << endl;
    }
}
