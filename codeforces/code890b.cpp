#include<bits/stdc++.h>

using namespace std;

vector<int>v[200001];
vector<int>num;

int main()
{
	int n, a;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		v[a].push_back(i);
		num.push_back(a);
	}
	int k,ind;
	ind = v[num[0]][v[num[0]].size()-1];
	k = num[0];
	for(int i = 1; i < num.size(); i++)
	{
		if(v[num[i]][v[num[i]].size()-1] < ind)
		{
			ind = v[num[i]][v[num[i]].size()-1];
			k = num[i];
		}
	}
	cout << k << endl;
	return 0;
}
	
	
	
