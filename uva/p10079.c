#include<stdio.h>
int main()
{
	long long n,x;
	while(1)
	{
	     scanf("%lld",&n);
	     if(n<0)
	     break;
	     x=(n+1)*n/2;
	     printf("%lld\n",++x);
	}
	return 0;
}