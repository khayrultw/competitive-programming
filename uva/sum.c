#include<stdio.h>
int main()
{
	long long a,i,sum=0;
	scanf("%lld",&a);
	for(i=1;i<=a;i++)
	sum+=i;
	printf("%lld\n",sum);
}