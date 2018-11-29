#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b=0)
{
	if(a%b==0)
		return b;
	return gcd(b, a%b);
}

bool bin(vector<int> v, int x, int a, int b)
{
	if(a>b)
		return false;
	int mid = (a+b)/2;
	if(v[mid]==x)
		return true;
	if(v[mid]<x)
		bin(v, x, mid+1, b);
	else
		bin(v, x, a, mid-1);
}
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v, gv;
	int n, x, gc;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		gv.push_back(x);
	}
	bool f;
	for(int i=0;i<gv.size();i++)
	{
		int j = i+1;
		gc = gv[j];
		f = false;
		for(int k=j+1;k<gv.size();k++)
		{
			gc = gcd(gc, gv[k]);
			if(gc == gv[i])
			{
				f = true;
				break;
			}
			if(gc % gv[i]!=0)
			{
				gc = gv[++k];
			}
		}
		if(!f)
			v.push_back(gv[i]);
	}
	
	f = false;
	for(int i=0;i<v.size()-1;i++)
	{
		gc = v[i];
		for(int j=i+1;j<v.size();j++)
		{
			if(bin(gv, gcd(gc,v[j]), 0, gv.size()-1)==false)
			{
				f = true;
				break;
			}
		}
		if(f)
			break;
	}
	if(f)
		cout << -1 << endl;
	else
	{cout << v[0];
	for(int i=1;i<v.size();i++)
		cout <<" " <<  v[i];
	cout << endl;
	}
	return 0;
}
