#include<bits/stdc++.h>

using namespace std;

const double gammaa =  0.57721566490153286060651209008;

int main()
{
	int cas=0, t, n;
	double ans[1000001];
	ans[0] = 0.0;
	for(int i=1; i <= 1000000; i++)
		ans[i] = ans[i-1] + 1.0 / i;
	scanf("%d", &t);
	while( ++cas <= t)
	{
		scanf("%d", &n);
		if(n <= 1000000)
			printf("Case %d: %.10lf\n", cas, ans[n]);
		else
			printf("Case %d: %.10lf\n", cas, log(n) + gammaa + 1.0 / (2 *n));
	}
	return 0;
}
