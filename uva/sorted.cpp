#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int cas = 0, t, i, arr[10002], n , k, cont ;
    cin >> t ;
    while( ++cas <= t )
    {
        cin >> n ;
        for(i = 0; i < n; i++ )
        {
            cin >> arr[i] ;
        }
        k = 1 ;
        cont = 0 ;
        for(i = 0; i < n; i++)
        {
            if(arr[i] == k )
            {
                cont++ ;
                k++ ;
            }
        }
        cout << "Case " << cas << ": " << n-cont << endl;
    }
    return 0;
}
