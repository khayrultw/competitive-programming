#include<bits/stdc++.h>

using namespace std;

struct node
{
	int nod, start, finish;
};

node graph[16];
vector<int> v[16];
bool vis[16];
int dfs_time;

bool operator<(const node &a, const node &b)
{
	return a.finish > b.finish;
}

void dfsTime(int n)
{
	vis[n] = true;
	graph[n].start = ++dfs_time;
	for(int i = 0; i < v[n].size(); i++)
	{
		if(!vis[v[n][i]])
			dfsTime(v[n][i]);
	}
	graph[n].finish = ++dfs_time;
}

void dfs(int n)
{
	vis[n] = true;
	for(int i = 0; i < v[n].size(); i++)
	{
		if(!vis[v[n][i]])
			dfs(v[n][i]);
	}
}

int main()
{
	int t, cas = 0, a, b, n, m;
	cin >> t;
	while(++cas <= t)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			graph[i].nod = i;
			
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
		}
		dfs_time = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
				dfsTime(i);
		}
		sort(graph+1, graph+n+1);
		int sum = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= n; i++)
		{
			if(!vis[graph[i].nod])
			{
				sum++;
				dfs(graph[i].nod);
			}
		}
		cout << "Case " << cas << ": " << sum << endl;
		for(int i = 0; i < 16; i++)
			v[i].clear();
	}
	return 0;
}

