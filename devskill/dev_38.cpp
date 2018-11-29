#include<iostream>
#include<map>
#include<string>

using namespace std ;

int main()
{
    map< int, string> mp ;
    map< int, string> :: iterator it ;
    int t, n, m ;
    double tm ;
    string str ;
    cin >> t ;
    while( t-- )
    {
        cin >> n ;
        m = n ;
        while( n-- )
        {
            cin >> str >> tm ;
            mp[tm] = str ;
        }
        it = mp.end();
        it--;
        cout << it -> second << " " << mp.begin() -> second << endl;
        mp.clear();

    }
    return 0;
}
