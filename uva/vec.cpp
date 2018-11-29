#include<bits/stdc++.h>

using namespace std;
int dp[101];
int canWin(int n)
{
    if(dp[n]!=-1)
        return dp[n];
    if(canWin(n-2)==0 || canWin(n-3)==0 || canWin(n-5)==0)
    {
        return dp[n] = 1;
    }
    return dp[n] =0;
}

int main()
{
    int t,n;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    dp[0] = dp[1] = 0;
    for(int i=2;i<=100;i++)
        canWin(i);
    while(t--)
    {
        cin >> n;

        if(dp[n]==1)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}
