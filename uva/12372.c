#include<stdio.h>
int main()
{
	int t,l,w,h,tmp=0;
	scanf("%d",&t);
	while(++tmp<=t)
	{
		scanf("%d%d%d",&l,&w,&h);
		if(l<=20&&w<=20&&h<=20)
		printf("Case %d: good\n",tmp);
		else
		printf("Case %d: bad\n",tmp);
	}
	return 0;
}