#include<stdio.h>
int main()
{
	int sum,bot,i=0;
	while(scanf("%d",&bot)!=EOF)
	{
		sum=bot;
		if(bot==0)
		break;
		while(bot>=3)
		{
			sum+=bot/3;
			bot=bot/3+bot%3;
		}
		if(bot==2)
		sum=sum+1;
		printf("%d\n",sum);
	}
	return 0;
}