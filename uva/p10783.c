#include<stdio.h>
int main()
{
	int a,b,sum,cas=0,t,i;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&a);
		scanf("%d",&b);
		for(i=a;i<=b;i++)
		if(i%2)
		sum+=i;
		printf("Case %d: %d\n",++cas,sum);
	}
	return 0;
}
	