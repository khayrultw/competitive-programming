#include<stdio.h>
int main()
{
	int i,t,n,age[100],k=0;
	scanf("%d",&t);
	while(++k<=t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&age[i]);
		printf("Case %d: %d\n",k,age[n/2]);
	}
	return 0;
}