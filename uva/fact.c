#include<stdio.h>
long long fact(int n);
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if((n<8&&n>=0)||(n<0&&n%2==0))
		printf("Underflow!\n");
	    else if(n>=8&&n<=13)
	    printf("%lld\n",fact(n));
	    else
	    printf("Overflow!\n");
	}
	return 0;
}
long long fact(int n)
{
	long long f=1;
	while(1)
	{
		if(n==1)
		return f;
		f=f*n--;
	}
}
		