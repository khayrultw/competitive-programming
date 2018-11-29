#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		long long n, m, sum1, sum2, a1, a2, d, term;
		
		cin >> n >> m;
		
		a1 = (m+1);
		
		a2 = (3*m+1);
		
		term = n / (2*m);
		
		sum1 = m * (a1 + (term - 1) * 2 * m ) * term / 2;
		
		sum2 = m * (a2 + (term - 1) * 2 * m ) * term / 2;
		
		sum2 = sum2 - sum1;
		
		cout <<"Case " << cas << ": " << sum2 << endl;
	}
	return 0;
}

