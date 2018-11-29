#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long t, n, sum;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int root = sqrt(n);
		sum = 0;
		if(n<=0)
			goto l1;
		for(int i = 1; i <= root; i++)
			sum += n/i;
		//cout << sum << endl;
		for(int i = 1; i < root; i++)
			sum += i * ((n / i) - (n / (i +1)));
		//cout << sum << endl;
		for(int i = root + 1; i <= n / root; i++)
			sum += n / i;
	 l1:cout << sum << endl;
	}
	return 0;
}

