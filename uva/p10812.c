#include<stdio.h>
int main()
{
   long long s,d,x,y,n;
	while(scanf("%lld",&n)){
	while(n--)
	{
		scanf("%lld%lld",&s,&d);
		x=(s+d)/2;
		y=s-x;
		if(s>=d&&((s+d)%2==0))
		printf("%lld %lld\n",x,y);
		else
		printf("imposible\n");
	}
	}
	return 0;
}