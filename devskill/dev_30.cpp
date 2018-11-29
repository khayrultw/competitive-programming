#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<char, int > mp ;
    map<char, int > :: iterator it ;
    int t,tm=0,i;
    string str ;
    cin >> t;
    while( ++tm <= t )
    {
        cin >> str ;
        for( i = 0; i < str.size(); i++ )
            mp[str[i]]++;
        cout<< "Case " << tm << ":" << endl;
        for( it = mp.begin(); it != mp.end(); it++ )
            cout << it -> first << " " << it -> second <<endl;
        mp.clear();
    }
    return 0;
}
