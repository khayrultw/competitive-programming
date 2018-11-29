#include<bits/stdc++.h>

using namespace std;

bool isSub(char *s,char *sb,int pos) ;

int main()
{
    char str[100005],sub[1005] ;
    int t, q , i, j ;
    cin >> t ;
    while( t-- )
    {
        cin >> str ;
        cin >> q ;
        for(i=0;i<q;i++)
        {
            cin >> sub ;
            if(isSub(str,sub,0))
                cout << "y" << endl;
            else
                cout << "n" << endl;
        }
    }
    return 0;
}

bool isSub(char *s, char *sb,int pos)
{
    char str[100005],sub[1005] ;
    strcpy(str,s);
    int l = strlen(sb) ;
    if(l > strlen(s))
        return false ;
    str[l] = '\0' ;
    if(strcmp(str,sb)==0)
    {
            return true ;
    }
    return isSub(&s[pos+1],sb,pos+1);
}
