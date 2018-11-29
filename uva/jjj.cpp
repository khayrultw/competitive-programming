#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x,y,z,tmp,t;
    while(cin >> n >> m >> x >> y >> z)
    {
        t = m ;
        if(x>m)
        {
            x = x-m ;
            m=0;
        }
        else{
            m = m-x;
            x=0;
        }
        if(m>0)
        {
            tmp = y+z-m ;
        }
        if(n-t<=2*tmp)
            cout <<"Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
