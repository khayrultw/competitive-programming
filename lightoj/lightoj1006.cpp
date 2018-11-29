#include<bits/stdc++.h>

using namespace std;

#define MOD 10000007

int main()
{
	long long dp[10001], n, t, cas=0;
	cin >> t;
	while( ++cas <= t)
	{
		cin >> dp[0] >> dp[1] >> dp[2] >> dp[3] >> dp[4] >> dp[5] >> n;
		
		dp[0] = dp[0] % MOD;
		dp[1] = dp[1] % MOD;
		dp[2] = dp[2] % MOD;
		dp[3] = dp[3] % MOD;
		dp[4] = dp[4] % MOD;
		dp[5] = dp[5] % MOD;
		
		for(int i = 6; i <= n; i++)
		{
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
			dp[i] = dp[i] % MOD;
		}
		cout << "Case " << cas << ": " << dp[n] << endl;
	}
	return 0;
}
		 
