#include<stdio.h>
#include<math.h>
int main()
{
	long long n,x;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		x=sqrt(8*n+1)-1;
    	printf("%lld\n",x/2);
	}
	return 0;
}