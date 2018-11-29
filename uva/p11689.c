#include<stdio.h>
int main()
{
	int t,sum,bot,e,f,c;
	scanf("%d",&t);
	while(t--!=0)
	{
		sum=0;
		scanf("%d%d%d",&e,&f,&c);
		bot=e+f;
		while(bot>=c)
		{
			sum=sum+bot/c;
			bot=bot/c+bot%c;
		}
		printf("%d\n",sum);
	}
	return 0;
}