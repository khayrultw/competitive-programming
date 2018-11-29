#include<stdio.h>
#include<math.h>
int fac(int n,int a,int b);
int main()
{
	int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,61,53,57,67,71,73,79,83,87,97};
	int n,i,count=0,test=0;
	scanf("%d",&n);
	for(i=0;;)
	{
		if(n%prime[i]==0)
		{
			count++;
			n=n/prime[i];
			if(n==1){
			printf("%d^%d",prime[i],count);
			break ; }
		}
		else
		{
			if(count!=0)
			printf("%d^%d*", prime[i], count);
			i++;
			count=0;
		}
	if(i>24)
	break;
	}
	if(n<10000 && n>100)
	    printf("%d^1",n);
	if(n>10000)
	    test=fac(n,100,10000);
	    if(test)
	    printf("\nyeah I got it");
	return 0;
}
int fac(int n, int a,int b)
{
	int n,i,count=0,j,k;
	for(;;)
	{
		for(i=a;i<=b;i++)
		{
			k=1;
			for(j=2;j<=sqrt(b);j++)
			{
				if(i%j==0)
				k=0;
			}
			if(k){
			   if(n%i==0){
			   	printf("%dno",n);
			   	count++;
			   	n=n/i;
			   	if(n==1){
		   	printf("2nd%d^%d",i,count);
		   	break ; }
			   }
	       	else
	       	{
	    	  	if(count!=0)
		     	printf("1st%d^%d*", i, count);
			      count=0;
	     	  }
			}
		}
	if(i>=b)
	break;
	}
	if(n<b)
	printf("3rd%d^1",n);
	else
	fac(n,b,b*b);
	return 1;
}