#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		char s[10];
		long long sum = 0, x;
		int n;
		scanf("%d", &n);
		printf("Case %d:\n", cas);
		for(int i = 0; i < n; i++)
		{
			scanf("%s", s);
			if(strcmp(s, "donate")==0)
			{
				scanf("%lld", &x);
				sum += x;
			}
			else
				printf("%lld\n", sum);
		}
	}
	return 0;
}
				
