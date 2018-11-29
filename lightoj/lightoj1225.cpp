#include<bits/stdc++.h>

using namespace std;

long long revs(long long n)
{
	long long rev = 0;
	while(n)
	{
		rev = rev*10 + (n%10);
		n = n/10;
	}
	return rev;
}
		
int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		long long n;
		scanf("%lld", &n);
		if(n == revs(n))
			printf("Case %d: Yes\n", cas);
		else
			printf("Case %d: No\n", cas);
	}
	return 0;
}
