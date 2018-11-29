#include<stdio.h>
int main()
{
	int n,k,p,t,tmp,x;
	scanf("%d",&t);
	tmp=0;
	while(++tmp<=t)
	{
		scanf("%d%d%d",&n,&k,&p);
		x=k+(p%n);
		if(x<=n)
		printf("Case %d: %d\n",tmp,x);
		else
		printf("Case %d: %d\n",tmp,x%n);
	}
	return 0;
}