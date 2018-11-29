#include<bits/stdc++.h>

using namespace std ;
long long divi[1000000],tmp[1000000],n,sum ;
int main()
{
    int t, cas=0,i,j,k;
    cin >> t ;
    while( ++cas<=t )
    {
        cin >> n ;
        long long sq = sqrt(n) ;
        j = k = 0 ;
        divi[j++] = 1 ;
        //clock_t t = clock();
        for(i=2;i<=sq;i++)
        {
            if(n%i==0)
            {
                divi[j++] = i ;
                if(i!=n/i)
                    tmp[k++] = n/i ;
            }
        }
       // cout << (1.00*clock()-t)/CLOCKS_PER_SEC << endl;
        k = k-1 ;
        for(;k>=0;k--)
            divi[j++] = tmp[k] ;
        if(n!=1)
            divi[j++] = n ;
        k = j ;
        int kk = j ;
        for(i=0;i<k;i++)
                cout << divi[i] << endl;
        sum = 0 ;
        for(i=0;i<k;i++)
        {
            cout << kk << " " << divi[i] << endl;
            sum += kk*divi[i] ;
            cout << sum << endl;
            kk--;
            sum += kk*divi[i] ;
            cout << sum << endl;
        }
        cout << "Case " << cas << ": " << sum << endl;
    }
    return 0;
}
