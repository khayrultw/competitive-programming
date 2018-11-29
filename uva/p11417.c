#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int n,i,j,k=0,g;
	while(++k<=100)
	{
		g=0;
		scanf("%d",&n);
		if(n==0)
		break;
		for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			g+=gcd(i,j);
		}
		printf("%d\n",g);
	}
	return 0;
}
int gcd(int a,int b)
{
	int tmp;
	while(1)
	{
		if(a%b==0)
		return b;
		tmp=a;
		a=b;
		b=tmp%b;
	}
}