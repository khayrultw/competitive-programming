#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int t , i ;
    char str[1001] ;
    cin >> t ;
    while( t-- )
    {
        cin >> str ;
        int len = strlen(str) ;
        sort(str,str+len) ;
        char ch = str[0] ;
        for(i = 0; i < len-1 ; i++ )
        {
            if(str[i]==ch)
                continue ;
            else if(str[i+1]==str[i])
                str[i] = ch ;
            else ;
        }
        sort(str,str+len) ;
        cout << str << endl;
    }
    return 0;
}
