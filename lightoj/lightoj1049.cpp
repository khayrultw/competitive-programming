#include<bits/stdc++.h>

using namespace std;

struct node
{
	int v, cost;
	bool f;
};

vector<node> vec[101];
bool vis[101];
int sum1, sum2;

void dfs(int);

int main()
{
	//ios_base::sync_with_stdin(0); cin.tie(0);
	int t, cas = 0, n, a, b, c;
	cin >> t;
	while(++cas<=t)
	{
		cin >> n;
		node tmp;
		for(int i=0;i<n;i++)
		{
			cin >> a >> b >> c;
			tmp.v = b ;
			tmp.cost = c;
			tmp.f = true;
			vec[a].push_back(tmp);
			tmp.v = a;
			tmp.f = false;
			vec[b].push_back(tmp);
		}
		memset(vis, false, sizeof(vis));
		sum1 = sum2 = 0;
		if(vec[a][0].f)
			sum1 += vec[a][0].cost;
		else
			sum2 += vec[a][0].cost;
		vis[vec[a][0].v] = true;
		dfs(vec[a][0].v);
		cout << "Case " << cas << ": " << min(sum1,sum2) << endl;
		for(int i=0;i<=100;i++) vec[i].clear();
	}
	return 0;
}

void dfs(int n)
{
	for(int i=0; i<vec[n].size();i++)
	{
		if(!vis[vec[n][i].v])
		{
			cout << vec[n][i].cost << endl;
			if(vec[n][i].f)
				sum1 += vec[n][i].cost;
			else
				sum2 += vec[n][i].cost;
			vis[vec[n][i].v] = true;
			dfs(vec[n][i].v);
		}
	}
}
