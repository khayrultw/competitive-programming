#include<bits/stdc++.h>

using namespace std;

struct node
{
	int v,edge;
};

vector<node> vect[30001];
bool vis[300001];
int cost[300001],maxx,indx;

void dfs(int n)
{
	vis[n] = true;
	//cout << "YES" << endl;
	for(int i=0;i<vect[n].size();i++)
	{
		if(vis[vect[n][i].v] == false)
		{
			cost[vect[n][i].v] = cost[n]+vect[n][i].edge ;
			if(cost[vect[n][i].v]>maxx)
			{
				maxx = cost[vect[n][i].v] ;
				indx = vect[n][i].v;
			}
			dfs(vect[n][i].v);
		}
	}
}
		
int main()
{
	int t,cas=0,n,a,b,c;
	node tmp;
	cin >> t;
	while(++cas<=t)
	{
		cin >> n;
		for(int i=0;i<n-1;i++)
		{
			cin >> a >> b >> c;
			tmp.v = b;
			tmp.edge = c;
			vect[a].push_back(tmp);
			tmp.v = a;
			vect[b].push_back(tmp);
		}
		memset(vis,false,sizeof(vis));
		memset(cost,0,sizeof(cost));
		maxx = -1;
		dfs(0);
		memset(vis,false,sizeof(vis));
		memset(cost,0,sizeof(cost));
		maxx = -1;
		dfs(indx);
		cout << "Case " << cas << ": " << cost[indx] << endl;
		for(int i=0;i<=30000;i++)
			vect[i].clear();
	}
	return 0;
}
		
