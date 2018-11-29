#include<stdio.h>
long long gcd(long long a,long long b);
int main()
{
	
    int t,n,tmp=0,i;
    long long num[100],g,prod,sum,z;
    scanf("%d",&t);
    while(++tmp<=t)
    {
    	sum=0;
    	prod=1;
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
    		scanf("%lld",&num[i]);
        for(i=0;i<n;i++)
            prod=prod*num[i];
        for(i=0;i<n;i++)
            sum=sum+prod/num[i];
       z=n*prod;
       g=gcd(sum,z);
       
       printf("Case %d: %d/%d",tmp,z,sum);
    }
}
long long gcd(long long a,long long b)
{
	long long tmp;
	while(1)
	{
		if(b%a==0)
		return a;
		tmp=a;
		a=b%a;
		b=tmp;
	}
}