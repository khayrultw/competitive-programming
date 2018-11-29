#include<bits/stdc++.h>

using namespace std;
int main()
{
    long long t, cas=0, ox,oy,ax,ay,bx,by;
    cin >> t ;
    while( ++cas<=t)
    {
        cin >> ox >> oy >> ax >> ay >> bx >> by ;
        double len,theta,a,b,c;
        a=sqrt(((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)));
        b=sqrt(((ox-bx)*(ox-bx)) + ((oy-by)*(oy-by)));
        c=sqrt(((ox-ax)*(ox-ax)) + ((oy-ay)*(oy-ay)));
        theta = acos((b*b+c*c-a*a)/(2*b*c)) ;
        len = b*theta;
        printf("Case %lld: %.8lf\n",cas,len);
    }
    return 0;
}
