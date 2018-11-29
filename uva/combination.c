#include<stdio.h>
int fact(int n);
int main()
{
	int n,test,a,b,c;
	scanf("%d",&n);
	test=0;
	while(++test<=n)
	{
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",test,fact(a)/(fact(a-b)*fact(b)));
	}
	return 0;
}
int fact(int n)
{
	int i,fac=1;
	if(n==0)
	return 1;
	while(n)
	fac=fac*n--;
	return fac;
}