#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long x1,x2,x3,y1,y2,y3,a,b,area;
    int t,cas=0;
    cin >> t ;
    while( ++cas<=t )
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 ;
        a = x1+x3-x2;
        b = y1+y3-y2;
        area = x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2) ;
        printf("Case %d: %lld %lld %lld\n",cas,a, b, abs(area));
    }
    return 0;
}
