#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[101], n, m, x, y, t, cas = 0, j;
	char ch;
	cin >> t;
	while( ++cas <= t)
	{
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", cas);
		bool f = false;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[j]);
		}
		for(int i = 0; i < m; i++)
		{
			scanf("%c", &ch);
			if(ch=='S')
			{
				scanf("%d", &x);
				for(j = 0; j < n; j++)
				{
					a[j] += x;
				}
			}
			else if(ch=='M')
			{
				scanf("%d", &x);
				for(j = 0; j < n; j++)
				{
					a[j] *= x;
				}
			}
			else if(ch=='D')
			{
				scanf("%d", &x);
				for(j = 0; j < n; j++)
				{
					a[j] /= x;
				}
			}
			else if(ch=='R')
			{
				f = !f;
			}
			else
			{
				scanf("%d", &y);
				int tmp = a[x];
				a[x] = a[y];
				a[y] = tmp;
			}
			if(!f)
				for(j = 0; j < n; j++)
				{
					if(j)
						printf(" ");
					printf("%d", a[j]);
				}
			else
				for(j = n-1; j >= 0; j--)
				{
					if(j)
						printf(" ");
					printf("%d", a[j]);
				}
			printf("\n");
			
		}
	}
	return 0;
}	
				
