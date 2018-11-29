#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,k;
    char str[101] ;
    map<char,int> mp ;
    map<char,int> :: iterator it ;
    cin >> n >> k ;
    cin >> str ;
    for(i=0;i<n;i++)
    {
        mp[str[i]]++;
    }
    int maxx = 0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(maxx<it->second)
            maxx = it->second;
    }
    if(maxx<=k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    mp.clear();
    return 0;
}
