#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	freopen("output.txt", "w", stdout);
	int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
	cin >> t;
	while(++cas <= t)
	{
		int n, freq[25], num[101];
		for(int i = 0; i < 25; i++) freq[i] = 0;
		for(int i = 0; i <=100; i++) num[i] = i;
		scanf("%d", &n);
		for(int i = 0; i < 25; i++)
		{
			for(int j = prime[i]; j <= n; j += prime[i])
			{
				while(num[j] % prime[i] == 0)
				{
					freq[i]++;
					num[j] = num[j] / prime[i];
				}
			}
		}
		printf("Case %d: %d = ", cas, n);
		int i;
		for(i = 0; i < 25; i++)
		{
			if(freq[i]){
				printf("%d (%d)", prime[i], freq[i]);
				break;
			}
		}
		for( i = i+1; i < 25; i++)
		{
			if(freq[i])
				printf(" * %d (%d)", prime[i], freq[i]);
		}
		printf("\n");
		
	}
	return 0;
}

			
