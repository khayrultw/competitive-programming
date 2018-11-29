#include<bits/stdc++.h>

using namespace std ;

int main()
{
     int n,k,day[105],sum=0,candi=0,coun=0 ;
     bool f = true ;
     cin >> n >> k ;
     for(int i=0;i<n;i++)
     {
        cin >> day[i] ;
        if(f)
        {
            coun++ ;
            candi+=day[i];
            if(candi>8)
            {
                sum+=8 ;
                candi = candi-8 ;
            }
            else
            {
                sum+=candi ;
                candi = 0;
            }
            if(sum>=k)
               f = false ;
        }
     }
     if(!f)
        cout << coun << endl;
    else
        cout << -1 << endl;
     return 0;
}
