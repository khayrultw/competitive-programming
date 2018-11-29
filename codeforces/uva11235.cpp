#include<bits/stdc++.h>

using namespace std;

int ar[100001];

struct tree
{
	int freq, value, left, right;
	tree()
	{
		freq=0;
	}
}seg[100001*3];

void build(int at,int l, int r)
{
	if(l==r)
	{
		seg[at].left=seg[at].right=r;
		seg[at].freq=1;
		seg[at].value=ar[l];
		return ;
	}
	int fr=0,val;
	map<int,int> mp;
	map<int,int> :: iterator it;
	for(int i=l; i<=r;i++)
	{
		mp[ar[i]]++;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(fr<it->second)
		{
			fr=it->second;
			val=it->first;
		}
	}
	mp.clear();
	seg[at].freq = fr;
	seg[at].value = val;
	seg[at].left=l;
	seg[at].right=r;
	int mid = (l+r)/2;
	build(2*at, l, mid);
	build(2*at+1, mid+1, r);
}

pair<int,int> find(int at, int l, int r)
{
	if(seg[at].left>=l && seg[at].right<=r)
		return make_pair(seg[at].freq,seg[at].value);
	if(seg[at].left>r || seg[at].right<l)
		return make_pair(0,0);
	pair<int,int> a = find(2*at, l,r);
	pair<int,int> b = find(2*at+1,l,r);
	if(a.second==b.second)
	{
		return make_pair(a.first + b.first, a.second);
		
	}
	if(a.first>=b.first)
		return a;
	return b;
	
}		

int main()
{
	freopen("out.txt", "w",stdout);
	int  t, cas=0, n, q;
	while(cin >> n && n!=0)
	{
		cin >> q;
		for(int i=1; i<=n;i++)
		{
			cin >> ar[i];
		}
		
		build(1,1,n);
		int l , r;
		for(int i=1;i<=q;i++)
		{
			cin >> l >> r;
			pair<int,int> at = find(1, l, r);
			printf("%d\n", at.first);
		}
			
	}
	return 0;
}
			
