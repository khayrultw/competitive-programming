#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		int r1, r2, h, p;
		cin >> r1 >> r2 >> h >> p;
		double k = 1.00 * (r1 - r2) / h;
		double ans = PI*(r2*r2*p+r2*k*p*p+k*k*p*p*p/3);
		printf("Case %d: %.10lf\n", cas, ans);
	}
	return 0;
}
        
				
