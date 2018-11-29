#include<stdio.h>
int main()
{
	int n,tmp;
	long long a,b,c;
	scanf("%d",&n);
	tmp=n;
	while(tmp--)
	{
		if(n<2 || n>20)
		break;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c&&a+c>b&&b+c>a)
		printf("OK\n");
		else
		printf("Wrong!!\n");
	}
	return 0;
}
		