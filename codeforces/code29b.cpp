#include<bits/stdc++.h>

using namespace std;

int main()
{
    double R,D,x,y,r;
    int i,n,sum=0;
    scanf("%lf%lf",&R,&D);
    scanf("%d",&n);
    int det, tmp = R-D ;
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&r);
        det = x*x+y*y ;
        if(det<=tmp*tmp || det>R*R)
            continue;
        if(sqrt(det)+r<=R && sqrt(det)-r>=tmp)
            sum++;
    }
    printf("%d\n",sum) ;
}
