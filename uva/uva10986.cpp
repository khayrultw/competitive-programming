#include<bits/stdc++.h>

using namespace std;

#define _ <<" "<<

const long long INF = 999999999999999;

struct node
{
	long long v, cost;
	void setV(long long _v, long long _cost)
	{
		v = _v;
		cost = _cost;
	}
};

vector<node> vec[20000];
long long dist[20000];

void dijkstra(long long s)
{
	dist[s] = 0;
	priority_queue<int> q;
	s = -1 * s;
	q.push(s);
	long long e;
	node k;
	while(!q.empty())
	{
		e = -1 * q.top();
		q.pop();
		for(int i = 0; i < vec[e].size();i++)
		{
			k = vec[e][i];
			if(dist[k.v] > dist[e] + k.cost)
			{
				dist[k.v] = dist[e] + k.cost;
				q.push(-1 * k.v);
			}
		}
	}
}
	
int main()
{
	long long n, m, a, b, c;
	long long t, cas = 0;
	cin >> t;
	node e;
	while( ++cas <= t )
	{
		for(int i = 0; i < 20000; i++) dist[i] = INF;
		cin >> n >> m ;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			e.setV(b, c);
			vec[a].push_back(e);
			e.setV(a, c);
			vec[b].push_back(e);
		}
		dijkstra(1);
		if(dist[n] == INF)
			cout << "Case " << cas << ": Impossible" << endl;
		else
			cout << "Case " << cas << ":"  _ dist[n] << endl;
			
		for(int i = 0; i < 20000; i++)
			vec[i].clear();
	}
	return 0;
}
	
