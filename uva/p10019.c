#include<stdio.h>
int main()
{
	int sum1,sum2,i,tmp;
	int m,n,z;
	scanf("%d",&n);
	while(n--)
	{
		sum1=0;
		sum2=0;
		scanf("%d",&m);
		tmp=m;
		while(tmp)
		{
			z=tmp%10;
			tmp=tmp/10;
			if(z==1|| z==2||z==4||z==8)
			sum1++;
			else if(z==7)
			sum1+=3;
			else
			{
				if(z)
				sum1+=2;
			}
		}
	   tmp=m;
	   while(tmp)
	   {
	   	if(tmp&1)
			sum2++;
			tmp=tmp/2;
	   }
	   printf("%d %d\n",sum2,sum1);
	}
	return 0;
}
	   