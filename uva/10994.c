#include<stdio.h>
int modd(int n);
int main()
{
	long long sum,g;
	int x,y,i,n,z;
	while(1)
	{
		scanf("%d%d",&x,&y);
		n=modd(x);
		printf("$%d\n",n);
		sum=n;
		if(x%10==0)
		z=0;
		else
		z=n;
		for(i=x+1;i<=y;i++)
		{
			if(z==9)
			{
				if(n==9)
				n=0;
				sum+=++n;
				z=0;
			}
			else
			sum+=++z;
			g=sum;
			printf("%d\n",sum);
		}
		printf("last%d\n",g);
	}
}	
int modd(int n)
{
	int z;
	while(1)
	{
		z=n%10;
		if(z)
		return z;
	}
}
		