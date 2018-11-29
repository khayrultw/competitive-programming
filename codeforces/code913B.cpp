#include<bits/stdc++.h>

using namespace std;

int par[1001];
int child[1001];

int main()
{
	int n,a;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		scanf("%d", &a);
		par[a]++;
		child[i+1] = a;
	}
	for(int i=2; i <= n; i++)
	{
		if(par[i]!=0)
			par[child[i]]--;
	}
	for(int i = 1; i <= n; i++)
	{
		if(par[i]!=0 && par[i]!=3)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
