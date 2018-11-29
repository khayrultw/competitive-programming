#include<stdio.h>
int main()
{
	long long a,b,c;
	while(1)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==0&&b==0&&c==0)
		break;
		if((a*a+b*b==c*c)||(b*b+c*c==a*a)||(a*a+c*c==b*b))
		printf("right\n");
		else
		printf("wrong\n");
	}
	return 0;
}