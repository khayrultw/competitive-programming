#include<stdio.h>
int main()
{
	long long n,z;
	while(scanf("%lld",&n)!=EOF)
	{
		z=n*(n+1)/2;
		printf("%lld\n",z*z);
	}
	return 0;
}