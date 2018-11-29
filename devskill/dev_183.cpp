#include<iostream>

using namespace std;

long long mod( long long n, long long m ) ;

int main()
{
    long long n,t,tm=0;
    cin >> t ;
    while( ++tm<= t )
    {
        cin >> n ;
        cout << "Case " << tm << ": " << mod( n, 100000007 ) << endl ;
    }
    return 0;
}

long long mod( long long n, long long m )
{
    if( n == 2 )
        return 2;
    return ( ( n % m ) * mod( n-1, m ) ) % m ;
}
