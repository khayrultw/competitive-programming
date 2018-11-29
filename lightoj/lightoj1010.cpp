#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, t, cas = 0, ans;
	
	scanf("%d", &t);
	freopen("output.txt", "w", stdout);
	while(++cas <= t)
	{
		scanf("%d%d", &n, &m);
		
		if( m % 2 == 0 || n%2 == 0)
			ans = m * n / 2;
			
				
		else
			ans =  1 + (m / 2) + (n-1) * m / 2;
		
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}

			
		
