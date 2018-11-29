#include<bits/stdc++.h>

using namespace std;

vector<int> v[101];
bool vis[101];
int t;

struct node
{
	int tim2, x;
}tim[101];


void dfs(int n)
{
	++t;
	vis[n] = true;
	for(int i = 0; i < v[n].size(); i++)
	{
		if(!vis[v[n][i]])
			dfs(v[n][i]);
	}
	tim[n].tim2 = ++t;
}

bool cmp(node &a, node &b)
{
	return a.tim2 > b.tim2 ;
}

int main()
{
	int n, m, arr[101];
	while(cin >> n >> m && (n != 0 || m != 0))
	{
		int a, b;
		t = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
		}
		for(int i = 1; i <= n; i++) tim[i].x = i;
		for(int i = 0; i <= n; i++)
			vis[i] = false;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
				dfs(i);
		}
		sort(tim+1, tim+n+1, cmp);
		for(int i = 1; i <= n; i++)
		{
			if(i!=1)
				cout << " ";
			cout << tim[i].x;
		}
		cout << endl;
		for(int i = 0; i <= n; i++)
			v[i].clear();
	}
	return 0;
}
	
