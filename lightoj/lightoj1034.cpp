#include<bits/stdc++.h>

using namespace std;

struct node
{
	int vir, start, finish;
};

node tim[10001];
int dfs_time;
vector<int> v[10001];
bool vis[10001];

bool cmp(const node &a, const node &b)
{
	return a.finish > b.finish;
}

void dfsTime(int n)
{
	vis[n] = true;
	tim[n].start = ++dfs_time;
	for(int i=0; i<v[n].size(); i++)
	{
		if(!vis[v[n][i]])
			dfsTime(v[n][i]);
	}
	tim[n].finish = ++dfs_time;
}

void dfs(int n)
{
	vis[n] = true;
	for(int i=0; i<v[n].size(); i++)
	{
		if(!vis[v[n][i]])
			dfs(v[n][i]);
	}
}

int main()
{
	int t, cas = 0, n, m, a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(++cas <= t)
	{
		cin >> n >> m;
		for(int i=0; i<m; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
		}
		for(int i=1; i<=n; i++)
			tim[i].vir = i;
			
		memset(vis, false, sizeof(vis));
		dfs_time = 0;
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
				dfsTime(i);
		}
		memset(vis, false, sizeof(vis));
		int sum = 0;
		sort(tim+1, tim+n+1, cmp);
		//for(int i=1; i<=n; i++)
			//cout << tim[i].vir << " " << tim[i].finish << endl;
		for(int i=1; i<=n; i++)
		{
			if(!vis[tim[i].vir])
			{
				sum++;
				dfs(tim[i].vir);
			}
		}
		cout << "Case " << cas << ": " << sum << endl;
		for(int i=0; i<=n; i++)
			v[i].clear();
	}
	return 0;
}

