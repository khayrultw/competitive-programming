#include<bits/stdc++.h>

using namespace std;

vector<int> v[10001];
int vis[10001];
bool f;

void dfs(int n)
{
	vis[n] = 1;
	for(int i=0; i<v[n].size(); i++)
	{
		if(f || vis[v[n][i]]==1)
		{
			f = true;
			return ;
		}
		if(!vis[v[n][i]])
			dfs(v[n][i]);
	}
	vis[n] = 2;
}

int main()
{
	int t, cas = 0, n;
	string a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(++cas <= t)
	{
		map<string, int> mp;
		cin >> n;
		int k = 0;
		for(int i=0; i<n; i++)
		{
			cin >> a >> b;
			if(!mp[a])
				mp[a] = ++k;
			if(!mp[b])
				mp[b] = ++k;
			v[mp[a]].push_back(mp[b]);
		}
		memset(vis, false, sizeof(vis));
		f = false;
		for(int i=1; i<=k; i++)
		{
			dfs(i);
			if(f)
				break;
		}
		if(f)
			cout << "Case " << cas << ": No" << endl;		
		else
			cout << "Case " << cas << ": Yes" << endl;
		for(int i=0; i<10001; i++)
			v[i].clear();
	}
	return 0;
}

