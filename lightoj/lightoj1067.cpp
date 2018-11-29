#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000003

ll bigMod(ll a, ll b)
{
	if(b == 1)
		return a;
	if(b&1)
		return (a * bigMod(a, b - 1)) % MOD;
	ll x = bigMod(a, b>>1);
	return (x * x) % MOD;
}

ll ans, fact[1000001];

int main()
{		
	fact[0] = 1;
	for(ll i = 1; i <= 1000000; i++)
		fact[i] = (i * fact[i-1]) % MOD ;
	int t, cas = 0;
	ll n, k;
	cin >> t;
	while(++cas <= t)
	{
		scanf("%lld%lld", &n, &k);
		ans = 1;
		ll tmp = (fact[k] * fact[n-k]) % MOD;
		tmp = bigMod(tmp, MOD-2);
		ans = (tmp * fact[n]) % MOD;
	    printf("Case %d: %lld\n", cas, ans);
	}
	return 0;
}

