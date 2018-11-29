#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,m;
    double angleh,anglem,angle;
    while(scanf("%d:%d",&h,&m) && (h!=0 || m!=0))
    {
        angleh = (h%12)*30+1.00*m*0.5 ;
        anglem = m*6;
        angle = abs(angleh-anglem) ;
        if(angle > 180 )
        {
            angle = 360 - angle ;
        }
        printf("%.3lf\n",angle) ;
    }
    return 0 ;
}
