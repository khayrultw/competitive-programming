#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		long long n, tmp;
		scanf("%lld", &n);
		tmp = n;
		if(n%2!=0)
			goto lb;
		while(n%2==0)
			n /= 2;
		if(n==1)
			goto lb;
		printf("Case %d: %lld %lld\n", cas, n, tmp/n);
		continue;
	lb: printf("Case %d: Impossible\n",cas);
	}
	return 0;
}
