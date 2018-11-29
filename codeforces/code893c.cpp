#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll rep[100001];
vector<ll> v[100001], gold;

ll find(ll n)
{
	if(rep[n] == n)
		return n;
	return rep[n] = find(rep[n]);
}

int main()
{
	ll n, m, a, b;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		gold.push_back(a);
	}
	ll x, y;
	for(int i=1; i <= n; i++) rep[i] = i;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		x = find(a);
		y = find(b);
		if(x!=y)
			rep[x] = y;
	}
	set<ll> st;
	set<ll> :: iterator it;
	for(int i=1; i <= n; i++) 
	{
		v[find(i)].push_back(i);
		st.insert(find(i));
	}
	ll sum = 0, minx;
	for(it = st.begin(); it!=st.end();it++)
	{
		minx = 2000000000;
		for(int i = 0; i < v[*it].size();i++)
		{
			if(minx > gold[v[*it][i]-1])
			minx = gold[v[*it][i]-1];
		}
		sum+=minx;
	}
	cout << sum << endl;
	return 0;
}
	
