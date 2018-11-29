#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    string str;
    cin >> t ;
    getchar();
    while( t-- )
    {
        getline( cin, str );
        reverse( str.begin(), str.end());
        cout << str << endl ;
    }
    return 0;
}
