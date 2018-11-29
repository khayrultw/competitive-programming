#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int n,m,z,count;
	while (scanf("%d", &n)!=EOF)
	{
		count=0;
		for (m=1; m<= n; m++)
		{
			z = gcd(m,n);
			if (z!=1&&z!=n)
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
int gcd(int a,int b)
{
	int tmp;
	while(1)
	{
		if(b%a==0)
    	return a;
    	tmp=a;
    	a=b%a;
    	b=tmp;
	}
}
	