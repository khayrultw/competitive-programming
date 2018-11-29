#include<bits/stdc++.h>

using namespace std;
#define MAX 100
int main()
{
    int n,m,w,sum[MAX],i,xsum,cas=0,j,t;
   // ofstream fcout("file.txt");
    cin>> t ;
    while( ++cas<=t )
    {
        cin >> n >> m ;
        for(i=1;i<=n;i++)
        {
            xsum=0;
            for(j=1;j<=m;j++)
            {
                cin >> w ;
                xsum+=w ;
            }
            sum[i] = xsum ;
        }
        xsum = 0 ;
        for(i=1;i<=n;i++)
            xsum ^= sum[i] ;
        if(xsum>0)
            cout << "Case " << cas << ": Alice" << endl;
        else
             cout << "Case " << cas << ": Bob" << endl;
    }
    return 0;
}
