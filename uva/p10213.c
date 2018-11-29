#include<stdio.h>
#include<math.h>
int main()
{
	long long n,z;
	int s;
	scanf("%d",&s);
	while(s--)
	{
		scanf("%lld",&n);
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		z=pow(2,n-1);
		printf("%lld\n",z);
	}
	return 0;
}