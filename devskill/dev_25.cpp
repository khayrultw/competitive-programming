#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

char hi_lo( char s);

int main()
{
    int t;
    string str, res;
    string :: iterator it;
    cin >> t;
    while( t-- )
    {
        cin >> str ;
        for( it = str.begin(); it != str.end(); it++ )
            *(it) = tolower( *(it));
        res = str ;
        reverse(str.begin(), str.end());
        if( res == str )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

