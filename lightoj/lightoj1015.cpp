#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, cas = 0;
	//freopen("output.txt", "w", stdout);
	cin >> t;
	
	while(++cas <= t)
	{
		cin >> n;
		int x, sum = 0;
		for(int i = 1; i <=n; i++)
		{
			scanf("%d", &x);
			if(x>0)
				sum += x;
		}
		cout << "Case " << cas << ": " << sum << endl ;
	}
	return 0;
}

