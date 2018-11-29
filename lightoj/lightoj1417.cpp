#include<bits/stdc++.h>

using namespace std;

struct node
{
	int start, finish;
};

node tim[50001];
int dfs_time;
vector<int> v[50001];
bool vis[50001];

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

int main()
{
	int t, cas = 0, n, a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(++cas<=t)
	{
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
		}
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				memset(vis, false, sizeof(vis));
				dfs_time = 0;
				dfsTime(i);
			}
		}
		int ind, finish;
		ind = 1;
		finish = tim[1].finish;
		for(int i=2; i<=n; i++)
		{
			if(tim[i].finish > finish)
			{
				ind = i;
				finish = tim[i].finish;
			}
		}
		cout << "Case " << cas << ": " << ind << endl;
		for(int i=0; i<50001; i++)
			v[i].clear();
	}
	return 0;
}
