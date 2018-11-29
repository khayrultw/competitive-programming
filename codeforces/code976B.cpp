#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long m, n, k, i, j, x;
    cin >> m >> n >> k;
    if(k < m)
    {
        cout << k+1 << " 1" << endl;
        return 0; 
    }
    k = k - m;
    i = m - (k/(n-1));
    j = k % (n-1);
    //cout << i << " " << j << endl;
    if(i%2==0)
        j += 2;
    else
        j = n - j;
    cout << i << " " << j << endl;
    return 0;

}