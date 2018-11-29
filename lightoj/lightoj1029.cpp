#include<bits/stdc++.h>

using namespace std;

struct node
{
	int u,v,cost;
};

vector<node>vect;
vector<node> :: iterator it;
int max_cost,min_cost,par[101];

bool cmp1(const node &a,const node &b)
{
	return a.cost<b.cost;
}

bool cmp2(const node &a,const node &b)
{
	return a.cost>b.cost;
}

int find(int n)
{
	if(n==par[n])
		return n;
	return par[n] = find(par[n]);
}

int minimum()
{
	int sum=0, a, b;
	//cout<< sum << endl;
	for(it=vect.begin(); it!=vect.end(); it++)
	{
		a = find((*it).u);
		b = find((*it).v);
		if(a!=b)
		{
			par[a] = b;
			sum += (*it).cost ;
		}
		//cout<< sum << endl;
	}
	return sum;
}

int main()
{
	int t,cas=0,n,a,b,c;
	cin >> t;
	node tmp;
	while(++cas<=t)
	{
		cin >> n;
		while( cin >> a >> b >> c )
		{
			if(a==0 && b==0 && c==0)
				break;
			tmp.u = a;
			tmp.v = b;
			tmp.cost = c;
			vect.push_back(tmp);
		}
		for(int i=0;i<=n;i++) par[i] = i;
		sort(vect.begin(),vect.end(),cmp1);
		min_cost = minimum();
		for(int i=0;i<=n;i++) par[i] = i;
		sort(vect.begin(),vect.end(),cmp2);
		max_cost = minimum();
		max_cost += min_cost;
		cout << "Case " << cas << ": ";
		if(max_cost&1)
			cout << max_cost << "/2" << endl;
		else
			cout << max_cost/2 << endl;
		vect.clear();
	}
	return 0;
}
	
