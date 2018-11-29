#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,i;
    double tmp;
    vector < double > num ;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        for( i = 0 ; i < n ; i++ )
        {
            cin >> tmp ;
            num.push_back(tmp);
        }
        sort( num.begin() , num.end() ) ;
        for( i = 0 ; i < n ; i++ )
            cout << num[i] << " " ;
        cout << endl ;
        num.clear() ;
    }
    return 0;
}
