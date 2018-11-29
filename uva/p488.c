#include<stdio.h>
void fun(int n);
void fn(int n);
int main()
{
	int amp,freq,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&amp,&freq);
		while(freq--)
		{
			fun(amp);
			fn(amp);
			if(freq!=0||t!=0)
			printf("\n");
		}
	}
	return 0;
}
void fun(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
      	for(j=1;j<=i;j++)
      	printf("%d",i);
      	printf("\n");
	}
}
void fn(int n)
{
	int i,j;
	for(i=n-1;i>=1;i--)
	{
      	for(j=1;j<=i;j++)
      	printf("%d",i);
      	printf("\n");
	}
}
      	