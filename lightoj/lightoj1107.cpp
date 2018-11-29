#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, cas = 0;
	
	cin >> t;
	
	while(++cas <= t)
	{
		int x1,x2,y1,y2,n,x,y;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		printf("Case %d:\n", cas);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			if((x>=x1 && x<=x2) && (y>=y1 && y<=y2))
				printf("Yes\n");
			else
				printf("No\n");
		}
		
	}
	return 0;
}
			
