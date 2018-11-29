#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n, sum;
	int t, cas = 0;
	cin >> t;
	while(++cas <= t)
	{
		scanf("%lld", &n);
		int root = sqrt(n);
		sum = 0;
		for(int i = 1; i <= root; i++)
			sum += n/i;
		//cout << sum << endl;
		for(int i = 1; i < root; i++)
			sum += i * ((n / i) - (n / (i +1)));
		//cout << sum << endl;
		for(int i = root + 1; i <= n / root; i++)
			sum += n / i;
	 	printf("Case %d: %lld\n", cas, sum);
	}
	return 0;
}

