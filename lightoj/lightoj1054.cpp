#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAX 1000000
#define ll long long

int stat[1+MAX/32];
ll prime[1000001];

int setp(int n, int p) 
{
	return n = n | (1 << p);
}

bool check(int n, int p)
{
	return (bool)(n & (1 << p));
}

void seive()
{
	ll sq = sqrt(MAX);
	for(ll i = 3; i <= sq; i+=2)
	{
		if(check(stat[i>>5], i&31)==0)
		{
			for(ll j = (ll)i*i; j <= MAX; j += i<<1)
			{
				stat[j>>5] = setp(stat[j>>5], j&31);
			}
		}
	}
	int i=0;
	prime[++i] = 2;
	for(int j = 3; j <= MAX; j += 2)
	{
		if(check(stat[j>>5], j&31)==0)
			prime[++i] = j;
	}
}

ll bigMod(ll a, ll b)
{
	if(b == 1)
		return a;
	if(b&1)
		return (a * bigMod(a, b - 1)) % MOD;
	ll x = bigMod(a, b>>1);
	return (x * x) % MOD;
}

int main()
{
	seive();
	map<ll, ll> mp;
	map<ll, ll> :: iterator it;
	ll a,b,sum;
	int cas = 0, t;
	cin >> t;
	while( ++cas <= t)
	{
		cin >> a >> b;
		for(ll i = 1; prime[i] <= sqrt(a); )
		{
			if(a==1)
				break;
			if(a%prime[i]==0)
			{
				mp[prime[i]]++;
				a = a / prime[i];
			}
			else
				i++;
		}
		if(a!=1)
			mp[a]++;
		ll ans = 1;
		for(it = mp.begin(); it!=mp.end(); it++)
		{
			 ll x = bigMod(it->first,it->second*b+1);
			 x = (x - 1 + MOD) % MOD;
			 ll y = bigMod(it->first-1, MOD-2);
			 ans  = ((ans % MOD) * (x % MOD)) % MOD;
			 ans = (ans * y) % MOD;
		}
		printf("Case %d: %lld\n", cas, ans);
		mp.clear();
	}
	return 0;
}
