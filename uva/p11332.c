#include<stdio.h>
int rec(long long n);
int main()
{
	long long n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		break;
		printf("%d\n",rec(n));
	}
	return 0;
}
int rec(long long n)
{
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n=n/10;
	}
	if(sum%10==sum)
	return sum;
	else
	return rec(sum);
}
		