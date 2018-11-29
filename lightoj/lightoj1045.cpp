#include<bits/stdc++.h>

using namespace std;

int main()
{
	double fact[1000001];
	int i, j, t, cas=0, a, b;
	fact[0] = fact[1] = 0;
	for(i = 2; i <= 1000000; i++)
		fact[i] = fact[i-1] + log10(1.0*i);
	cin >> t;
	while( ++cas <= t)
	{
		scanf("%d%d", &a, &b);
		int ans = fact[a] / log10(b);
		printf("Case %d: %d\n", cas, ans+1);
	}
	return 0;
}
		
