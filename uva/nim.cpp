#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nim[300],sum, k, t, cas=0;
    cin >> t ;
    while( ++cas<=t )
    {
        cin >> k ;
        for( int i = 1; i<=2*k; i++)
            cin >> nim[i] ;
        sum=0;
        for( int i = 2; i<=2*k; i+=2)
        {
            sum ^= (nim[i]-nim[i-1]-1) ;
        }
        if(sum!=0)
            printf("Case %d: Alice\n",cas);
        else
             printf("Case %d: Bob\n",cas);
    }
    return 0;
}
