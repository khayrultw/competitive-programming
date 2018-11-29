#include<bits/stdc++.h>

using namespace std;

struct node
{
	int u,v,cost;
};

struct adjnode
{
	int v,cost;
}

bool cmp(const node &a,const node &b)
{
	return a.cost<b.cost;
};

vector<node> vect;
bool vis[51];
