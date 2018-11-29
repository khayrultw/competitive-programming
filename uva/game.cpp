#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,tmp;
    bool f = false ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        if(tmp&1)
        {
            f = true ;
            break;
        }
    }
    if(f)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
