#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int t,m ;
    cin >> t ;
    while( t-- )
    {
        cin >> s ;
        if(s=="0")
            cout << 1 << endl;
        else if(s=="1")
            cout << 66 << endl;
        else
        {
            int len = s.size();
            m = (s[len-1]-48)%5 ;
            if(m==0)
                cout << 76 << endl;
            else if(m==1)
                cout << 16 << endl;
            else if(m==2)
                cout << 56 << endl;
            else if(m==3)
                cout << 96 << endl;
            else
                cout << 36 << endl;
        }
    }
    return 0;
}
