#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	//freopen("output", "w", stdout);
	long long fac[21];
	fac[0] = 1;
	for(int i = 1; i <= 20; i++) fac[i] = i * fac[i-1];
	
	scanf("%d",&t);
	while(++cas <= t)
	{
		long long n;
		vector<int> v;
		scanf("%lld",&n);
		for(int i = 20; i >= 0; i--)
		{
			if(fac[i]<=n)
			{
				v.push_back(i);
				n -= fac[i];
			}
		}
		//cout << n << endl;
		if(v.size()==0 || n)
			printf("Case %d: impossible", cas);
		else
		{
			printf("Case %d: ", cas);
			for(int i = v.size()-1; i >=0; i--)
			{
				printf("%d!", v[i]);
				if(i)
					printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}

