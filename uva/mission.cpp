#include<bits/stdc++.h>

using namespace std;

struct adjnode
{
	int v, cost;
};

struct node
{
	int u,v,cost;
};

vector<adjnode>vect[501];
int par[501], max_cost[501];
priority_queue<node> pq;
bool vis[501];

bool operator<(const node &a, const node &b)
{
	return a.cost>b.cost;
}

int find(int n)
{
	if(n==par[n])
		return n;
	return par[n] = find(par[n]);
}

void minimumDenger()
{
	node tmp;
	adjnode adj;
	int a,b;
	while(!pq.empty())
	{
		tmp = pq.top();
		pq.pop();
		a = find(tmp.u);
		b = find(tmp.v);
		if(a!=b)
		{
			par[a] = b;
			adj.v = tmp.u;
			adj.cost = tmp.cost;
			vect[tmp.v].push_back(adj);
			adj.v = tmp.v;
			vect[tmp.u].push_back(adj);
		}
	}
}

void bfs(int n)
{
	int tmp;
	queue<int> q;
	max_cost[n] = 0;
	vis[n] = true;
	q.push(n);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		for(int i=0; i<vect[tmp].size(); i++)
		{
			//cout << vect[tmp][i].v ;
			if(vis[vect[tmp][i].v] == false)
			{
				if(max_cost[tmp]<vect[tmp][i].cost)
				{
					max_cost[vect[tmp][i].v] = vect[tmp][i].cost ;
				}
				else
					max_cost[vect[tmp][i].v] = max_cost[tmp];
				vis[vect[tmp][i].v] = true;
				q.push(vect[tmp][i].v);
			}
		}
		//cout << endl;
	}
}

int main()
{
	int t,cas=0,n,m,query;
	node tmp;
	cin >> t;
	while(++cas<=t)
	{
		cin >> n >> m;
		for(int i=0;i<m;i++)
		{
			cin >> tmp.u >> tmp.v >> tmp.cost;
			pq.push(tmp);
		}
		for(int i=0;i<n;i++)
			par[i] = i;
		minimumDenger();
		memset(vis,false,sizeof(vis));
		cin >> query;
		bfs(query);
		cout << "Case " << cas << ":" << endl;
		for(int i=0;i<n;i++)
		{
			if(vis[i])
				cout << max_cost[i] << endl;
			else
				cout << "Impossible" << endl;
		}
		for(int i=0;i<=500;i++)
			vect[i].clear();
	}
	return 0;
}




