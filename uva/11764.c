#include<stdio.h>
int main()
{
	int i,t,tmp,n,h[50];
	int low,high;
	scanf("%d",&t);
	tmp=0;
	while(++tmp<=t)
	{
		low=0; high=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&h[i]);
		for(i=0;i<n-1;i++)
		{
			if(h[i]>h[i+1])
			low++;
			if(h[i]<h[i+1])
			high++;
		}
		printf("Case %d: %d %d\n",tmp,high,low);
	}
	return 0;
}