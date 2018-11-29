#include<bits/stdc++.h>

using namespace std;

long long solve(long long n, long long k)
{
    if(k==1)
        return n * n;
    return ((n-1) * (n-1) ) +  solve(n-1, k-1);
}

int main()
{
    long long t, cas = 0, n, k;
    cin >                     (++cas <= t)
    {
        cin >> n >> k;
        cout << "Case " << cas << ": " << solve(n, k) << endl;
    }
    return 0;
}
