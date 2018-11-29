#include<stdio.h>
int main()
{
	int n,sum;
	while(1)
	{
		sum=0;
		scanf("%d",&n);
		if(n==0)
		break;
		while(n)
		{
			sum+=n*n;
			n--;
		}
		printf("%d\n",sum);
	}
	return 0;
}