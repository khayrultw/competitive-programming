#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		int a, b;
		cin >> a >> b;
		int sum = 4*(abs(a-b)+a)+19;
		printf("Case %d: %d\n", cas, sum);
	}
	return 0;
}
