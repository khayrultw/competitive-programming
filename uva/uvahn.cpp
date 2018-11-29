#include<bits/stdc++.h>

using namespace std;

const double gammaa =  0.57721566490153286060651209008;

int main()
{
	int cas=0, t, n;
	double ans[1000001], Hn;
	ans[0] = 0.0;
	for(int i=1; i <= 1000000; i++)
		ans[i] = ans[i-1] + 1.0 / i;
	scanf("%d", &t);
	while( ++cas <= t)
	{
		scanf("%d", &n);
		if(n <= 1000000)
			Hn = n * ans[n];
		else
			Hn = n * (log(n) + gammaa + 1.0 / (2 *n));
		printf("%.5lf\n", Hn);
		
	}
	return 0;
}
