#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int t;
    double r, s, tmp , m;
    cin >> t ;
    while( t-- )
    {
        cin >> r >> s ;
        tmp = sqrt(2) * r ;
        m = abs( s - tmp ) ;
        if( m < 0.01 )
            cout << "Yes" << endl ;
        else
            cout << "No" << endl ;
    }
    return 0 ;
}
