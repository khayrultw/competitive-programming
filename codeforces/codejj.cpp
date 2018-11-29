#include<bits/stdc++.h>

using namespace std;

int main()
{
	map<int,int> mp;
	int ar1[2001], ar2[2001], n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> ar1[i];
		mp[ar1[i]] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> ar2[i];
		mp[ar2[i]] = 1;
	}
	int sum=0,tmp;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[ar1[i]^ar2[j]])
				sum++;
		}
	}
	if(sum&1)
		cout << "Koyomi" << endl;
	else
		cout << "Karen" << endl;
	return 0;
}
