#include<bits/stdc++.h>

using namespace std;

int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,area;
    int t,cas=0;
    cin >> t ;
    while( ++cas<=t )
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
       a = x1-x2;
       b = y1-y2;
       c = y1-x1;
       area = abs(b*x3+a*y3+c)/sqrt(a*a+b*b) ;

    }
}
