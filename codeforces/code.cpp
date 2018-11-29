#include<bits/stdc++.h>

using namespace std;

int main()
{
    double l,r,x,y,k;
    cin >> l >> r >> x >> y >> k ;
    if((l/x)<=k && r/y>=k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
