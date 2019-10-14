#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

int main()
{
    int n;
    cin >> n;
    vector<lint> v1(n+1), v2(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v1[i];
    for(int i = 1; i <= n; i++)
        cin >> v2[i];
    
    lint dp[2][n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n-1; i++)
    {
        //cout << "ok" << endl;
        dp[0][i+1] = max(dp[0][i+1], dp[1][i]+v1[i+1]);
        if(i < n-1)
            dp[0][i+2] = max(dp[0][i+2], dp[1][i]+v1[i+2]);
        dp[1][i+1] = max(dp[1][i+1], dp[0][i]+v2[i+1]);
        if(i < n-1)
            dp[1][i+2] = max(dp[1][i+2], dp[0][i]+v2[i+2]);
    }

    cout << max(dp[0][n], dp[1][n]) << endl;
    return 0;
}