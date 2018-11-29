#include<bits/stdc++.h>

using namespace std;

vector<int> v;
bool cmp(const int &a, const int &b)
{
	return a>b;
}

void findDiv(int n)
{
	int t = sqrt(n);
	for(int i=1; i<t; i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	if(t*t==n)
		v.push_back(t);
	else if(n%t==0)
	{
		v.push_back(t);
		v.push_back(n/t);
	}
}

int find(int at, int k)
{
	if(at>=v.size() || k == 0)
		return -1;
	int x = 1;
	x  = x << k;
	int y = 1;
	x--;
	y = y << (k-1);
	//cout << v[at] << " " << x*y << endl;
	if(v[at]==x*y)
		return v[at];
	if(v[at] < x*y)
		return find(at, k-1);
	else
		return find(at+1, k);
}
	
int main()
{
	long long n;
	cin >> n;
	findDiv(n);
	sort(v.begin(), v.end(), cmp);
	cout << find(0, 15) << endl;
	return 0;
}
	
